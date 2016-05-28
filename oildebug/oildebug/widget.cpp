#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ui->IPLineEdit->setText("192.168.1.6");
    //ui->comLineEdit->setText("30001");
    ui->IPLineEdit->setEnabled(false);
    ui->comLineEdit->setEnabled(false);

    ui->funComboBox->setEnabled(false);
    ui->readPushButton->setEnabled(false);
    ui->modiPushButton->setEnabled(false);
    ui->confPushButton->setEnabled(false);
    ui->picturelabel->setScaledContents(true);
    ui->plainTextEdit->setEnabled(false);
     serverPort=30001;
     server=QHostAddress("192.168.1.6");

    /*建立socket*/
    udpClient = new QUdpSocket(this);
    udpClient->bind(0); //0--由系统指定空闲的端口
    /*绑定有数据到来信号，执行读取数据*/
    connect(udpClient,SIGNAL(readyRead()),this,SLOT(readMessage()));
    /*绑定错误机制*/
    connect(udpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectpushButton_clicked()
{
    char *cmd;
    if(ui->connectpushButton->text()==tr("连接")){
        ui->connectpushButton->setText(tr("断开"));       
        /*显示时间*/
        QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
        QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
        ui->textBrowser->append(str);//显示时间
        ui->textBrowser->append(tr("正在连接......."));

        cmd=(char *)"NetCon";
        udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);

    }else if(ui->connectpushButton->text()==tr("断开")){
         ui->connectpushButton->setText(tr("连接"));
         ui->textBrowser->append(tr("断开连接......."));
         ui->funComboBox->setEnabled(false);
         ui->readPushButton->setEnabled(false);
         ui->modiPushButton->setEnabled(false);
         ui->confPushButton->setEnabled(false);

    }
}


void Widget::readMessage()
{
    QByteArray datagram; //拥于存放接收的数据报
    QByteArray recBuf;
    unsigned int realPacLen,pacNum,realPac;
    static unsigned int pacNumTemp=99;
    int i;
    static unsigned int photoLen,photoLenTemp=0;

    unsigned short int hostId;

   // qDebug()<<"data coming";

    while(udpClient->hasPendingDatagrams()) //拥有等待的数据报
    {
        //让 datagram 的大小为等待处理的数据报的大小,这样才能接收到完整的数据
        datagram.resize(udpClient->pendingDatagramSize());
        recBuf.resize(udpClient->pendingDatagramSize());

        udpClient->readDatagram(datagram.data(),datagram.size(),&server,&serverPort);

         //qDebug()<<"data coming"<<datagram;
        //ui->clientIPlineEdit->setText(client.toString());
        //ui->clientComlineEdit->setText(tr("%1").arg(clientPort));
        if(datagram.data()[0]==0x7e){
            reTran(datagram.data(),recBuf.data(),datagram.size());
            hostId=(unsigned short int)recBuf.data()[1];
            hostId=((unsigned short int)recBuf.data()[2])|(hostId<<8);
            unsigned char datatemp,warnFlag,preNum,flowNum;
            float voltage,pressure;
            double flow;

            if(hostId == 0x0002){ //生产数据
                char datagram[] = {0x7e,/*消息ID*/0x00,0x02,/*消息体属性*/0x00,0x00,/*消息体长度*/0x00,0x00,\
                               /*设备厂商和设备ID：0004005000*/0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
                               0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0,/*流水线ID*/0x00,0x00,\
                               /*校验位*/0x02,0x7e};
                udpClient->writeDatagram(datagram,sizeof(datagram)-1,server,serverPort);

            }else if(hostId == 0x0200){ //生产数据
                ui->textBrowser->append(tr("\n********开接收数据********"));
                QDataStream in(&recBuf,QIODevice::ReadOnly);
                for(i=0;i<26;i++){  //处理消息头
                    in >> datatemp;
                }

                in>>warnFlag;//报警信息
                ui->textBrowser->append(tr("报警信息 %1").arg(warnFlag));
                //in>>voltage;//电压信息

                memcpy(&voltage,&recBuf.data()[27],4);

                ui->textBrowser->append(tr("电压值: %1").arg(voltage));

                preNum=recBuf.data()[36];//压力表个数
                ui->textBrowser->append(tr("压力表个数: %1").arg(preNum));
                for(i=0;i<preNum;i++){
                    memcpy(&pressure,&recBuf.data()[38+5*i],4);
                    ui->textBrowser->append(tr("压力表数据: %1").arg(pressure));
                }

                flowNum=recBuf.data()[38+5*preNum];//流量计个数
                ui->textBrowser->append(tr("流量计个数: %1").arg(flowNum));

                memcpy(&pressure,&recBuf.data()[38+5*preNum+2],4);
                pressure=pressure/1000;
                ui->textBrowser->append(tr("压力数据: %1").arg(pressure));

                for(i=0;i<flowNum;i++){

                    ui->textBrowser->append(tr("第%1个流量计:").arg(i+1));
                    memcpy(&pressure,&recBuf.data()[38+5*preNum+2+25*i],4);
                    pressure=pressure/1000;
                    ui->textBrowser->append(tr("压力数据: %1").arg(pressure));

                    memcpy(&pressure,&recBuf.data()[38+5*preNum+6+25*i],4);
                    ui->textBrowser->append(tr("温度数据: %1").arg(pressure));

                    memcpy(&pressure,&recBuf.data()[38+5*preNum+10+25*i],4);
                    ui->textBrowser->append(tr("瞬时流量数据: %1").arg(pressure));

                    memcpy(&pressure,&recBuf.data()[38+5*preNum+14+25*i],4);
                    ui->textBrowser->append(tr("工况流量数据: %1").arg(pressure));

                    memcpy(&flow,&recBuf.data()[38+5*preNum+18+25*i],8);
                    ui->textBrowser->append(tr("总流量数据: %1").arg(flow));

            }

                ui->textBrowser->append(tr("********数据接收完毕********\n"));


            }else if(hostId == 0x0805){ //拍照应答
                photoLen=recBuf.data()[31] | (recBuf.data()[30]<<8);

                ui->textBrowser->append(tr("拍照成功,照片长度为: %1").arg(photoLen));


            }else if(hostId == 0x0801){//数据上传命令
                pacNum=recBuf.data()[28]|(recBuf.data()[27]<<8);
                realPacLen=(unsigned char)recBuf.data()[38]|((unsigned char)recBuf.data()[37]<<8);
                realPac=recBuf.data()[26]|(recBuf.data()[25]<<8);

                if(pacNum!=pacNumTemp || (pacNum==0 && photoLen != photoLenTemp)     ){ //两次包号不同,才接受
                    photoLenTemp = photoLen;//存储照片数据长度
                    pacNumTemp=pacNum;
                    QFile file( "temp.jpg" );
                    //QTextStream stream( &file);
                    if(pacNum==0){
                        ui->textBrowser->append(tr("\n*********开始接收照片********"));

                        ui->textBrowser->append(tr("照片总包个数为: %1").arg(realPac));

                        if(file.open(QIODevice::WriteOnly)){ //若是第0个包,就覆盖之前的文件
                            //for(i=0;i<realPacLen;i++)
                                //stream << recBuf.data()[39+i];
                            file.write(&(recBuf.data()[39]),realPacLen);
                        }
                        }else{
                            if(file.open(QIODevice::WriteOnly|QIODevice::Append)){ //追加写入方式打开
                                //for(i=0;i<realPacLen;i++)
                                    //stream << recBuf.data()[39+i];
                                file.write(&(recBuf.data()[39]),realPacLen);
                            }
                        }

                    ui->textBrowser->append(tr("开始接收第%1个包:").arg(pacNum));

                    ui->textBrowser->append(tr("包数据大小: %1").arg(realPacLen));
                    file.close();

                    if(pacNum == realPac-1){//传送完毕就显示图片
                        ui->textBrowser->append(tr("*********照片接收完毕********\n"));
                        ui->picturelabel->setPixmap(QPixmap("temp.jpg"));

                    }
                }

            }
        }else if(datagram.data()[0]=='S'){

            if(!strcmp(datagram.data(),"SNetOK")){
                ui->textBrowser->append(tr("连接成功"));

                ui->funComboBox->setEnabled(true);
                ui->readPushButton->setEnabled(true);
                ui->modiPushButton->setEnabled(true);
                //ui->confPushButton->setEnabled(false);

            }else if(!strcmp(datagram.data(),"SCamOK")){
                ui->textBrowser->append(tr("摄像机OK"));
            }else if(!strcmp(datagram.data(),"SCamERR")){
                ui->textBrowser->append(tr("摄像机ERROR"));
            }else if(!strcmp(datagram.data(),"SSouOK")){
                ui->textBrowser->append(tr("功放OK"));
            }else if(!strcmp(datagram.data(),"SSouERR")){
                ui->textBrowser->append(tr("功放ERROR,请检查音频文件是否存在!"));
            }else if(!strcmp(datagram.data(),"SDataOK")){
                ui->textBrowser->append(tr("接收数据OK"));
            }else if(!strcmp(datagram.data(),"SDataERR")){
                ui->textBrowser->append(tr("接收数据ERROR"));
            }else if(!strcmp(datagram.data(),"SRePaOK")){
                //ui->textBrowser->append(tr("返回参数成功"));
            }else if(!strcmp(datagram.data(),"SRePaERR")){
                ui->textBrowser->append(tr("读取参数ERROR"));
            }else if(!strcmp(datagram.data(),"SUpPaOk")){
                ui->textBrowser->append(tr("提交参数OK"));
            }else if(!strcmp(datagram.data(),"SUpPaERR")){
                ui->textBrowser->append(tr("提交参数ERROR"));
            }else if(!strcmp(datagram.data(),"SConFileERR")){
                ui->textBrowser->append(tr("参数配置文件不存在,请先提交参数!"));
            }else if(!strcmp(datagram.data(),"SRVERR")){
                ui->textBrowser->append(tr("电源或者红外驱动故障!"));
            }else if(!strcmp(datagram.data(),"SPREERR")){
                ui->textBrowser->append(tr("压力表无数据,请检查接线或压力表!"));
            }else if(!strcmp(datagram.data(),"SFLOERR")){
                ui->textBrowser->append(tr("流量计无数据,请检查接线或流量计!"));
            }else if(!strcmp(datagram.data(),"SBLOERR")){
                ui->textBrowser->append(tr("截断阀无数据,请检查接线或截断阀!"));
            }

        }else if(datagram.data()[0]=='p'){ //参数

           //qDebug()<<"pa is"<<datagram.data();

            char *s,prenum[3]={0,0,0},temp[2]={0,0};
            char IP[15],com[5];
            char dev[20];
            char deviceID[15]={0};

            s=strstr(datagram.data(),"ID:");
            if(s==NULL){
                ui->textBrowser->append(tr("设备ID读取失败"));
            }else{
                memcpy(deviceID,(s+3),10);
                ui->devidLineEdit->setText((QString)deviceID);
            }



            s=strstr(datagram.data(),"IP:");
            if(s==NULL){
                ui->textBrowser->append(tr("服务器IP读取失败"));
            }else{
                memset(IP,'\0',sizeof(IP));
                memcpy(IP,(s+3),15);
                for(i=0;i<15;i++){
                    if(IP[i] == '#'){
                        IP[i]='\0';
                    }
                }
                ui->severIPLineEdit->setText((QString)IP);
            }
            //printf("IP is %s\n",IP);

            s=strstr(datagram.data(),"COM:");
            if(s==NULL){
               ui->textBrowser->append(tr("服务器端口读取失败"));
            }else{
                memset(com,'\0',sizeof(com));
                memcpy(com,(s+4),5);
                for(i=0;i<5;i++){
                    if(com[i] == '#'){
                        com[i]='\0';
                    }
                }
                ui->severComLineEdit->setText((QString)com);
            }
            //printf("com is %s\n",com);
            s=strstr(datagram.data(),"IN:");
            if(s==NULL){
                ui->textBrowser->append(tr("设备信息读取失败"));
            }else{
                memcpy(dev,(s+3),20);
                prenum[0]=dev[0];
                prenum[1]=dev[1];
                ui->preNumLineEdit->setText((QString)prenum);
                temp[0]=dev[2];
                ui->flowNumLineEdit->setText((QString)temp);
                temp[0]=dev[3];
                ui->flowType1lineEdit->setText((QString)temp);
                temp[0]=dev[4];
                ui->flowAddr1lineEdit->setText((QString)temp);
                temp[0]=dev[5];
                ui->flowType2lineEdit->setText((QString)temp);
                temp[0]=dev[6];
                ui->flowAddr2lineEdit->setText((QString)temp);
                temp[0]=dev[7];
                ui->flowType3lineEdit->setText((QString)temp);
                temp[0]=dev[8];
                ui->flowAddr3lineEdit->setText((QString)temp);
                temp[0]=dev[9];
                ui->flowType4lineEdit->setText((QString)temp);
                temp[0]=dev[10];
                ui->flowAddr4lineEdit->setText((QString)temp);
                temp[0]=dev[11];
                ui->flowType5lineEdit->setText((QString)temp);
                temp[0]=dev[12];
                ui->flowAddr5lineEdit->setText((QString)temp);
                temp[0]=dev[13];
                ui->flowType6lineEdit->setText((QString)temp);
                temp[0]=dev[14];
                ui->flowAddr6lineEdit->setText((QString)temp);
                temp[0]=dev[15];
                ui->flowType7lineEdit->setText((QString)temp);
                temp[0]=dev[16];
                ui->flowAddr7lineEdit->setText((QString)temp);
                temp[0]=dev[17];
                ui->flowType8lineEdit->setText((QString)temp);
                temp[0]=dev[18];
                ui->flowAddr8lineEdit->setText((QString)temp);
                temp[0]=dev[19];
                ui->bloNumLineEdit->setText((QString)temp);

                 ui->textBrowser->append(tr("读取参数成功!"));
            }

        }
    }
}


void Widget::displayError(QAbstractSocket::SocketError)
{
    qDebug() << udpClient->errorString(); //输出错误信息
    ui->textBrowser->append(udpClient->errorString()); //循环显示
}

void Widget::on_readPushButton_clicked()
{
    char *cmd;
    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("读取参数!"));
    cmd=(char *)"ReadPara";
    udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);



}

void Widget::on_modiPushButton_clicked()
{
    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("正在修改参数....."));
    ui->confPushButton->setEnabled(true);
}

void Widget::on_confPushButton_clicked()
{
    ui->confPushButton->setEnabled(false);
    char *cmd;
    int n;
    char para[200]="parameter#IP:219.245.64.3####COM:30001#ID:0004005000#IN:04111000000000000001#HE:020#TR:000#DA:008#";
    QString ip,com,deviceid;
    //unsigned char preNum,
    char dev[20];

    //char preNum[2];
    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("提交参数!"));

    n=ui->devidLineEdit->text().length();
    if(n!=10){
        ui->textBrowser->append(tr("设备ID长度不正确!"));
        return;
    }
    deviceid=ui->devidLineEdit->text();
    memcpy(&para[42],deviceid.toAscii().data(),n);



    cmd=(char *)"UpPara";
    udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);
    ip=ui->severIPLineEdit->text();
    n=strlen(ip.toAscii().data());
    memcpy(&para[13],ip.toAscii().data(),n);
    para[13+n]='#';

    com=ui->severComLineEdit->text();
    n=strlen(com.toAscii().data());
    memcpy(&para[33],com.toAscii().data(),n);
    para[33+n]='#';

    int pre_num=ui->preNumLineEdit->text().toInt();
    //qDebug()<<"pre NUm is "<<pre_num;
    if(pre_num>=10){
        dev[0]='1';
        dev[1]=(char )(pre_num%10)+0x30;
        //qDebug("dev[1] is %c",dev[1]);
    }else{
        dev[0]='0';
        dev[1] = (char )(pre_num)+0x30;//*ui->preNumLineEdit->text().toAscii().data();//  toStdString().data();
        //qDebug("dev[1] is %c",dev[1]);
    }
    dev[2]=*ui->flowNumLineEdit->text().toAscii().data();

    dev[3]=*ui->flowType1lineEdit->text().toAscii().data();
    dev[4]=*ui->flowAddr1lineEdit->text().toAscii().data();
    dev[5]=*ui->flowType2lineEdit->text().toAscii().data();
    dev[6]=*ui->flowAddr2lineEdit->text().toAscii().data();
    dev[7]=*ui->flowType3lineEdit->text().toAscii().data();
    dev[8]=*ui->flowAddr3lineEdit->text().toAscii().data();
    dev[9]=*ui->flowType4lineEdit->text().toAscii().data();
    dev[10]=*ui->flowAddr4lineEdit->text().toAscii().data();
    dev[11]=*ui->flowType5lineEdit->text().toAscii().data();
    dev[12]=*ui->flowAddr5lineEdit->text().toAscii().data();
    dev[13]=*ui->flowType6lineEdit->text().toAscii().data();
    dev[14]=*ui->flowAddr6lineEdit->text().toAscii().data();
    dev[15]=*ui->flowType7lineEdit->text().toAscii().data();
    dev[16]=*ui->flowAddr7lineEdit->text().toAscii().data();
    dev[17]=*ui->flowType8lineEdit->text().toAscii().data();
    dev[18]=*ui->flowAddr8lineEdit->text().toAscii().data();

    dev[19]=*ui->bloNumLineEdit->text().toAscii().data();

    //qDebug("IP: %s " ,ip.toAscii().data());

    memcpy(&para[56],dev,20);
    udpClient->writeDatagram(para,sizeof(para),server,serverPort);

    //qDebug(" %s " ,para);
}


/*反转义函数*/
int Widget::reTran(char *buf1,char *buf2,int buf1_size)
{
    int i;
    int j=0;
    for(i=0;i<buf1_size;i++){
        if(buf1[i]==0x7d){
            switch (buf1[i+1]){
                case 0x01 :
                    buf2[j]=0x7d;
                    j++;
                    i++;
                    break;
                case 0x02 :
                    buf2[j]=0x7e;
                    j++;
                    i++;
                    break;
                }
            }
        else{
            buf2[j]=buf1[i];
            j++;
            }
        }
    return j;
}

void Widget::on_funComboBox_activated(const QString &arg1)
{
    char *cmd;
    if(arg1 == tr("相机测试")){
        ui->textBrowser->append(tr("相机测试"));
        cmd=(char *)"Camera";
        udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);
    }else if(arg1 == tr("功放测试")){
        ui->textBrowser->append(tr("功放测试"));
        cmd=(char *)"Sound";
        udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);
    }else if(arg1 == tr("仪表数据")){
        ui->textBrowser->append(tr("读取仪表数据"));
        cmd=(char *)"Data";
        udpClient->writeDatagram(cmd,strlen(cmd),server,serverPort);
    }else if(arg1 == tr("ARM重启")){
        ui->textBrowser->append(tr("ARM重启"));
    }else if(arg1 == tr("开截断阀")){
        ui->textBrowser->append(tr("开截断阀,危险!"));
    }else if(arg1 == tr("关截断阀")){
        ui->textBrowser->append(tr("关截断阀"));
    }else if(arg1 == tr("自检")){
        ui->textBrowser->append(tr("自检,暂不支持"));
    }else if(arg1 == tr("联网测试")){
        ui->textBrowser->append(tr("联网测试,暂不支持"));
    }


}

