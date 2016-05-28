#include "widget.h"
#include "ui_widget.h"

#define DEBUG 0

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ui->IPLineEdit->setText("192.168.1.6");
    //ui->comLineEdit->setText("30001");
    //ui->IPLineEdit->setEnabled(false);
    //ui->comLineEdit->setEnabled(false);

//#ifdef DEBUG
    ui->funComboBox->setEnabled(false);
    ui->readPushButton->setEnabled(false);
    ui->modiPushButton->setEnabled(false);
    ui->confPushButton->setEnabled(false);
    ui->picturelabel->setScaledContents(true);
    ui->plainTextEdit->setEnabled(false);
//#endif

    /*读取终端的IP和地址*/
    //serverPort=30001;
    //server=QHostAddress("192.168.1.136");
    serverPort = ui->comLineEdit->text().toInt();
    server=QHostAddress(ui->IPLineEdit->text());

    /*建立socket*/
    udpClient = new QUdpSocket(this);
    udpClient->bind(0); //0--由系统指定空闲的端口
    //udpClient->bind(QHostAddress("127.0.0.1"), 30002);

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
    Msg *msg;
    /*分配消息存储空间*/
    if( NULL == (msg=(Msg *)malloc(sizeof(Msg))) ){
        perror(" msg memery error\n");
    }

    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间


    if(ui->connectpushButton->text()==tr("连接")){
        ui->connectpushButton->setText(tr("断开"));       
        ui->textBrowser->append(tr("#######准备连接#######"));
        sen_cmd(msg,0x9901,0x00);//获取连接请求命令
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);//发送命令
    }else if(ui->connectpushButton->text()==tr("断开")){
         ui->connectpushButton->setText(tr("连接"));
         ui->textBrowser->append(tr("#######连接已经断开#######"));

//#ifdef DEBUG
         ui->funComboBox->setEnabled(false);
         ui->readPushButton->setEnabled(false);
         ui->modiPushButton->setEnabled(false);
         ui->confPushButton->setEnabled(false);
//#endif
         sen_cmd(msg,0x9901,0x01);//断开连接
         udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);//发送命令
    }
    /*释放空间*/
    free(msg);

}




/*接受消息*/
void Widget::readMessage()
{
    QByteArray datagram; //拥于存放接收的数据报
    QByteArray recBuf;
    unsigned int realPacLen,pacNum,realPac;
    static unsigned int pacNumTemp=99;
    int i;
    static unsigned int photoLen,photoLenTemp=0;
    unsigned short int hostId = 0x0000;

    //qDebug()<<"data coming";

    while(udpClient->hasPendingDatagrams()) //拥有等待的数据报
    {
       // qDebug()<<"data has come";
        //让 datagram 的大小为等待处理的数据报的大小,这样才能接收到完整的数据
        datagram.resize(udpClient->pendingDatagramSize());
        recBuf.resize(udpClient->pendingDatagramSize());//设置recBuf长度

        udpClient->readDatagram(datagram.data(),datagram.size(),&server,&serverPort);

         //qDebug()<<"data coming"<<datagram;
        //ui->clientIPlineEdit->setText(client.toString());
        //ui->clientComlineEdit->setText(tr("%1").arg(clientPort));
        if(datagram.data()[0]==0x7e){
            //qDebug()<<"data has 0x7e";
            /*反转义*/
            reTran(datagram.data(),recBuf.data(),datagram.size());
            hostId=(unsigned short int)((uchar)recBuf.data()[1]);
            hostId=((unsigned short int)((uchar)recBuf.data()[2]))|(hostId<<8);
            unsigned char datatemp,warnFlag,preNum,flowNum,valveNum;
            float voltage,pressure;
            double flow;
            //char valve;
//            qDebug()<<"######### Oildebug Retranfer:"<< ret<<"\n";
//            for(i=0;i<ret;i++){
//                qDebug()<<"0x"<< hex << (uchar)recBuf.data()[i]<<" ";
//            }
//            qDebug() << "\n#############\n";



           // qDebug() << "HostId:" <<"0x" <<hex << hostId;




            if(hostId == 0x0002){ //心跳包
                char datagram[] = {0x7e,/*消息ID*/0x00,0x02,/*消息体属性*/0x00,0x00,/*消息体长度*/0x00,0x00,\
                               /*设备厂商和设备ID：0004005000*/0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
                               0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0,/*流水线ID*/0x00,0x00,\
                               /*校验位*/0x02,0x7e};
                udpClient->writeDatagram(datagram,sizeof(datagram)-1,server,serverPort);

            }else if(hostId == 0x0200){ //生产数据

                ui->textBrowser->append(tr("\n********开接收数据********"));
                /*将recBuf绑定到输入流in中*/
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
                }//for

                flowNum=recBuf.data()[38+5*preNum];//流量计个数
                ui->textBrowser->append(tr("流量计个数: %1").arg(flowNum));

                //memcpy(&pressure,&recBuf.data()[38+5*preNum+2],4);
                //pressure=pressure/1000;
                //ui->textBrowser->append(tr("压力数据: %1").arg(pressure));

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

                }//for


                valveNum=recBuf.data()[38+5*preNum+25*flowNum+1+1];//截断阀个数
                ui->textBrowser->append(tr("截断阀个数: %1").arg(valveNum));

                for(i=0;i<valveNum;i++){
                    ui->textBrowser->append(tr("第%1个截断阀状态:%L2").arg( i+1).arg((int)recBuf.data()[38+5*preNum+25*flowNum+1+2+2*i]) );
                    //ui->textBrowser->append(tr("%1").arg((int)recBuf.data()[38+5*preNum+25*flowNum+1+2+2*i]));
                }
                ui->textBrowser->append(tr("********数据接收完毕********\n"));


            }else if(hostId == 0x0805){ //拍照应答
                photoLen=(uchar)recBuf.data()[31] | ((uchar)recBuf.data()[30]<<8);
                //photoLen=(unsigned int)((uchar)recBuf.data()[31]);
                //photoLen=((unsigned int)((uchar)recBuf.data()[30]))|(hostId<<8);
                ui->textBrowser->append(tr("拍照成功,照片长度为: %1").arg(photoLen));


            }else if(hostId == 0x0801){//数据上传命令
                pacNum=recBuf.data()[28]|(recBuf.data()[27]<<8);
                realPacLen=(unsigned char)recBuf.data()[38]|((unsigned char)recBuf.data()[37]<<8);
                realPac=recBuf.data()[26]|(recBuf.data()[25]<<8);

                if(pacNum!=pacNumTemp || (pacNum==0 && photoLen != photoLenTemp)     ){ //两次包号不同,才接受
                    photoLenTemp = photoLen;//存储照片数据长度
                    pacNumTemp=pacNum;
                    QFile file( "temp.jpg" );//文件不存在就创建
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
                    file.close();

                    ui->textBrowser->append(tr("开始接收第%1个包:").arg(pacNum));
                    ui->textBrowser->append(tr("包数据大小: %1").arg(realPacLen));

                    if(pacNum == realPac-1){//传送完毕就显示图片
                        ui->textBrowser->append(tr("*********照片接收完毕********\n"));
                        ui->picturelabel->setPixmap(QPixmap("temp.jpg"));
                    }
                }


            }else if(hostId == 0x8901){ //联网回应
                 //qDebug()<<"connect network";
                if(datagram.data()[25] == 0x00){
                    ui->textBrowser->append(tr("连接成功"));

                    ui->funComboBox->setEnabled(true);
                    ui->readPushButton->setEnabled(true);
                    ui->modiPushButton->setEnabled(true);
                    //ui->confPushButton->setEnabled(false);
                    ui->IPLineEdit->setEnabled(false);
                    ui->comLineEdit->setEnabled(false);
                }else if(datagram.data()[25] == 0x01){
                     ui->textBrowser->append(tr("连接断开"));
                }

            }else if(hostId == 0x8904){ //功放测试回应
                if(datagram.data()[25] == 0x00){    //成功
                    ui->textBrowser->append(tr("功放测试成功"));
                }else{
                    ui->textBrowser->append(tr("功放测试失败"));
                }
            }else if(hostId == 0x8905){ //联网测试回应
                if(datagram.data()[25] == 0x00){    //成功
                    ui->textBrowser->append(tr("联网测试成功"));
                }else{
                    ui->textBrowser->append(tr("联网测试失败"));
                }
            }else if(hostId == 0x890a){ //读取配置参数回应
                if(datagram.data()[25] == 0x00){    //成功
                    ui->textBrowser->append(tr("读取参数成功"));
                    /*处理参数*/
                    int len;
                    char bufTmp[18];
                    int index;
                    int i;
                    /*IP*/
                    len = (int)datagram.data()[27]; //IP 长度
                    index = 28;
                    memcpy(bufTmp,&datagram.data()[index],len);
                    bufTmp[len] = '\0';
                    ui->severIPLineEdit->setText((QString)bufTmp);
                    index += len;

                    /*COM*/
                    index++;
                    len = (int)datagram.data()[index++]; //COM 长度
                    memcpy(bufTmp,&datagram.data()[index],len);
                    bufTmp[len] = '\0';
                    ui->severComLineEdit->setText((QString)bufTmp);
                    index += len;

                    /*DeviceID*/
                    index++;
                    len = (int)datagram.data()[index++]; //DeviceID 长度
                    memcpy(bufTmp,&datagram.data()[index],len);
                    bufTmp[len] = '\0';
                    ui->devidLineEdit->setText((QString)bufTmp);
                    index += len;

                    /*气压计*/
                    index++;
                    len = (int)datagram.data()[index++]; //气压计数量
                    ui->preNumLineEdit->setText(QString::number(len));
                    for(i=0;i<len;i++){
                        char type,addr;
                        type = datagram.data()[index++];
                        addr = datagram.data()[index++];
                        set_pre(i, type, addr);
                    }
                    /*流量计*/
                    index++; //成功
                    len = (int)datagram.data()[index++]; //流量计数量
                    ui->flowNumLineEdit->setText(QString::number(len));
                    for(i=0;i<len;i++){
                        char type,addr;
                        type = datagram.data()[index++];
                        addr = datagram.data()[index++];
                        set_flow(i, type, addr);
                    }
                    /*截断阀*/
                    index++; //成功
                    len = (int)datagram.data()[index++]; //截断阀数量
                    ui->bloNumLineEdit->setText(QString::number(len));
                    for(i=0;i<len;i++){
                        char type,addr;
                        type = datagram.data()[index++];
                        addr = datagram.data()[index++];
                        set_blo(i, type, addr);
                    }

                    index+=2; //摄像头类型

                    /*心跳时间*/
                    if( datagram.data()[index++] == 0x00){
                        len = (int)datagram.data()[index++]; //时间长度
                        char time[10];
                        for(i=0;i<len;i++){
                            time[len-1-i]= datagram.data()[index++];
                        }
                        time[len] = '\0';
                        ui->heartTimlineEdit->setText((QString)time);
                    }
                    /*数据时间*/
                    if( datagram.data()[index++] == 0x00){
                        char time[10];
                        len = (int)datagram.data()[index++]; //时间长度
                        for(i=0;i<len;i++){
                            time[len-1-i]= datagram.data()[index++];
                        }
                        time[len] = '\0';
                        ui->datTimlineEdit->setText((QString)time);
                    }

                }else{//if(datagram.data()[25] == 0x00)
                    ui->textBrowser->append(tr("读取参数失败"));
                }
            }else if(hostId == 0x890b){ //提交配置参数回应
                if(datagram.data()[25] == 0x00){    //成功
                    ui->textBrowser->append(tr("参数提交成功"));

                }else{//if(datagram.data()[25] == 0x00)
                    ui->textBrowser->append(tr("参数提交失败"));

                }
            }//if(hostId == 0x0002)
        }//if(datagram.data()[0]==0x7e)
    }//while(udpClient->hasPendingDatagrams())

}


/*错误处理*/
void Widget::displayError(QAbstractSocket::SocketError)
{
    qDebug() << udpClient->errorString(); //输出错误信息
    ui->textBrowser->append(udpClient->errorString()); //显示错误信息
}


/*读取参数*/
void Widget::on_readPushButton_clicked()
{
    Msg *msg;
    /*分配空间*/
    if( NULL == (msg=(Msg *)malloc(sizeof(Msg))) ){
        perror(" msg memery error\n");
    }
    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("读取参数"));

    sen_cmd(msg, 0x990a,0x00);//读取命令参数
    /*发送命令*/
    udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    /*释放空间*/
    free(msg);
}


/*修改参数*/
void Widget::on_modiPushButton_clicked()
{
    /*显示时间*/
    QDateTime time=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("正在修改参数"));
    ui->confPushButton->setEnabled(true);
}



/*提交参数*/
void Widget::on_confPushButton_clicked()
{
   // ui->confPushButton->setEnabled(false);
   // char *cmd;
    int len = 0;
    int index = 0;
    //char para[200]="parameter#IP:219.245.64.3####COM:30001#ID:0004005000#IN:04111000000000000001#HE:020#TR:000#DA:008#";
    QString ip,com,deviceid,time;
    //unsigned char preNum,
    //char dev[20];
    int i;
    uchar message[500]={/*消息ID*/0x99,0x0b,/*消息体属性*/0x00,0x00,/*消息体长度*/0x00,0x00 ,
                        /*设备厂商和设备ID：0004005000*/0x30,0x30,0x30,0x31,0x30,0x30,0x30,0x31,0x00,0x00,
                        0x00,0x00,0x00,0x00,0x00,0x0,/*流水线ID*/0x00,0x00};

#if 0
                            //0x00---成功，0x01--失败
    /*成功与否*/0x00,/*IP长度读取成功与否*/0x00,/*IP长度*/0x0f,/*IP*/211.149.218.89,
     */*COM成功与否*/0x00,/*COM长度*/0x05,/*COM*/30001,/*设备ID成功与否*/0x00,
     */*设备ID长度*/0x08,/*设备ID*/0004005000,/*气压计成功与否*/0x00,
     */*气压计数量*/0x04,0x01,0x01,0x01,0x02,0x01,0x03,0x01,0x014,
     */*流量计成功与否*/0x00,/*流量计数量*/0x01,/*第一个流量计类型*/0x01,
     */*第一个流量计地址*/0x01,/*截断阀成功与否*/0x00,/*截断阀数量*/0x01,0x01,0x01,
     */*摄像头成功与否*/0x00,/*摄像头类型*/0x01,/*心跳成功与否*/0x00,
     */*心跳时间*/0x32,0x30,0x30,/*数据传输时间成功与否*/0x00,/*数据传输时间*/0x0,0x00,0x38

#endif


    //char preNum[2];
    /*显示时间*/
    QDateTime time1=QDateTime::currentDateTime();//获取系统当前时间
    QString str=time1.toString("yyyy-MM-dd hh:mm:ss ddd");//设置时间格式
    ui->textBrowser->append(str);//显示时间
    ui->textBrowser->append(tr("提交参数!"));

    index = 24;
    message[index++] = 0x00;

    /*IP，uchar型*/
    message[index++] = 0x00; //成功
    len = ui->severIPLineEdit->text().length();
    message[index++]=(uchar)len;
    ip = ui->severIPLineEdit->text();
    memcpy( &message[index],ip.toAscii().data(),len);
    index += len;

    /*COM，uchar型*/
    message[index++] = 0x00; //成功
    len = ui->severComLineEdit->text().length();
    message[index++]=(uchar)len;
    com = ui->severComLineEdit->text();
    memcpy( &message[index],com.toAscii().data(),len);
    index += len;

    /*DeviceID，uchar型*/
    message[index++] = 0x00; //成功
    len = ui->devidLineEdit->text().length();
    message[index++]=(uchar)len;
    deviceid = ui->devidLineEdit->text();
    memcpy( &message[index],deviceid.toAscii().data(),len);
    index += len;

    /*气压计*/
    message[index++] = 0x00; //成功
    len = ui->preNumLineEdit->text().toInt();
    message[index++] = (uchar)len;
    for(i=0;i<len;i++){
        get_pre(i,&message[index],&message[index+1] );
        index += 2;
    }

    /*流量计*/
    message[index++] = 0x00; //成功
    len = ui->flowNumLineEdit->text().toInt();
    message[index++] = (uchar)len;
    for(i=0;i<len;i++){
        get_flow(i,&message[index],&message[(index+1)]);
        index += 2;
    }

    /*截断阀*/
    message[index++] = 0x00; //成功
    len = ui->bloNumLineEdit->text().toInt();
    message[index++] = (uchar)len;
    for(i=0;i<len;i++){
        get_blo(i,&message[index],&message[(index+1)]);
        index += 2;
    }

    /*摄像头*/
    message[index++] = 0x00; //成功
    message[index++] = 0x01;

    /*心跳时间*/
    message[index++] = 0x00; //成功
    time = ui->heartTimlineEdit->text();
    len = time.length();
    message[index++]=(uchar)len;//存储时间长度
    for(i=0;i<len;i++){ //填充内容
        message[index++] = time.toAscii().data()[i];
    }
    //index += len;
    /*数据间隔时间*/
    message[index++] = 0x00; //成功
    time = ui->datTimlineEdit->text();
    len = time.length();
    message[index++]=(uchar)len;//存储时间长度
    for(i=0;i<len;i++){         //填充内容
        message[index++] = time.toAscii().data()[i];
    }
    //index += len;

    message[index] = check_byte(message,index);//校验
    index++;
    Msg *msg;
    int tran_num;
    if( NULL == (msg=(Msg *)malloc(sizeof(Msg))) ){
        perror(" msg memery error\n");
    }

    tran_num = transferr_func(message,&msg->buf[1],index); //转义
    msg->buf[0]=0x7e;
    msg->buf[tran_num+1]=0x7e;
    msg->len = tran_num+2;
    udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);

    free(msg);
}


/*下拉菜单处理函数*/
void Widget::on_funComboBox_activated(const QString &arg1)
{
    Msg *msg;

    if( NULL == (msg=(Msg *)malloc(sizeof(Msg))) ){
        perror(" msg memery error\n");
    }

    if(arg1 == tr("仪表数据")){
        ui->textBrowser->append(tr("读取仪表数据"));
        sen_cmd(msg,0x9902,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("功放测试")){
        ui->textBrowser->append(tr("功放测试"));
        sen_cmd(msg,0x9904,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("相机测试")){
        ui->textBrowser->append(tr("相机测试"));
        sen_cmd(msg,0x9903,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("ARM重启")){
        ui->textBrowser->append(tr("ARM重启"));
        sen_cmd(msg,0x9906,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("开截断阀")){
        ui->textBrowser->append(tr("开截断阀,危险!"));
        sen_cmd(msg,0x9907,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("关截断阀")){
        ui->textBrowser->append(tr("关截断阀"));
        sen_cmd(msg,0x9908,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("自检")){
        ui->textBrowser->append(tr("自检,暂不支持"));
        sen_cmd(msg,0x9909,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }else if(arg1 == tr("联网测试")){
        ui->textBrowser->append(tr("联网测试"));
        sen_cmd(msg,0x9905,0x00);
        udpClient->writeDatagram((char *)msg->buf,msg->len,server,serverPort);
    }

    free(msg);
}



/*命令打包函数*/
char Widget::sen_cmd(Msg *msg,unsigned short int messgae_id,unsigned char para)
{
    //int i;
    int trans_num;
    //int count=0;
    uchar message[]={/*消息ID*/0x00,0x02,/*消息体属性*/0x00,0x00,/*消息体长度*/0x00,0x00 ,
                        /*设备厂商和设备ID：0004005000*/0x30,0x30,0x30,0x31,0x30,0x30,0x30,0x31,0x00,0x00,
                        0x00,0x00,0x00,0x00,0x00,0x0,/*流水线ID*/0x00,0x00,/*参数*/0x00,/*校验位*/0xff};

    message[0]=(uchar)( (messgae_id>>8)&0x00ff );
    message[1]=(uchar)( messgae_id & 0x00ff );


//    for(i=0;i<16;i++){
//        message[6+i]=config.MD5_ID[i];
//    }

    message[24] = (uchar)para;

    message[25]=(uchar)check_byte( message,25 );
    trans_num=(uchar)transferr_func( message,&msg->buf[1] , 26 );
    msg->buf[0]=0x7e;
    msg->buf[trans_num+1]=0x7e;
    msg->len = trans_num+2;

//    for(i=0;i<msg->len;i++){
//        qDebug("0x%x ",msg->buf[i]);
//    }
    //qDebug

    return 0;
}


/*检验函数*/
uchar Widget::check_byte(uchar *buf,int size)
{
    int i;
    uchar temp=0x00;
    for(i=0;i<size;i++)
        temp=temp^buf[i];
    return temp;
}



/*转义函数*/
int Widget::transferr_func(uchar *from,uchar *to,int fromSize)
{
    int i;
    int j=0;
    for(i=0;i<fromSize;i++){
        if(from[i]==0x7e){
            to[j]=0x7d;
            j++;
            to[j]=0x02;
            j++;
        }else if(from[i]==0x7d){
            to[j]=0x7d;
            j++;
            to[j]=0x01;
            j++;
        }else{
            to[j]=from[i];
            j++;
        }
    }
    return j;
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
        }else{
            buf2[j]=buf1[i];
            j++;
        }
    }
    return j;
}



/*设置压力计参数*/
void Widget::set_pre(int num,char type,char addr)
{
   // char temp[2]={'\0','\0'};

    //qDebug()<<"type:"<<hex<<(uchar)type <<" addr:"<<hex<<(uchar)addr;

    switch (num)
    {
        case 0:
            ui->preType1lineEdit->setText( QString::number((int)type) );
            ui->preAddr1lineEdit->setText(QString::number((int)addr));
            break;
        case 1:
            ui->preType2lineEdit->setText(QString::number((int)type));
            ui->preAddr2lineEdit->setText(QString::number((int)addr));
            break;
        case 2:
            ui->preType3lineEdit->setText(QString::number((int)type));
            ui->preAddr3lineEdit->setText(QString::number((int)addr));
            break;
        case 3:
            ui->preType4lineEdit->setText(QString::number((int)type));
            ui->preAddr4lineEdit->setText(QString::number((int)addr));
            break;
        case 4:
            ui->preType5lineEdit->setText(QString::number((int)type));
            ui->preAddr5lineEdit->setText(QString::number((int)addr));
            break;
        case 5:
            ui->preType6lineEdit->setText(QString::number((int)type));
            ui->preAddr6lineEdit->setText(QString::number((int)addr));
            break;
        case 6:
            ui->preType7lineEdit->setText(QString::number((int)type));
            ui->preAddr7lineEdit->setText(QString::number((int)addr));
            break;
        case 7:
            ui->preType8lineEdit->setText(QString::number((int)type));
            ui->preAddr8lineEdit->setText(QString::number((int)addr));
            break;
        case 8:
            ui->preType9lineEdit->setText(QString::number((int)type));
            ui->preAddr9lineEdit->setText(QString::number((int)addr));
            break;
        case 9:
            ui->preType10lineEdit->setText(QString::number((int)type));
            ui->preAddr10lineEdit->setText(QString::number((int)addr));
            break;
        case 10:
            ui->preType11lineEdit->setText(QString::number((int)type));
            ui->preAddr11lineEdit->setText(QString::number((int)addr));
            break;
        case 11:
            ui->preType12lineEdit->setText(QString::number((int)type));
            ui->preAddr12lineEdit->setText(QString::number((int)addr));
            break;
        case 12:
            ui->preType13lineEdit->setText(QString::number((int)type));
            ui->preAddr13lineEdit->setText(QString::number((int)addr));
            break;
        case 13:
            ui->preType14lineEdit->setText(QString::number((int)type));
            ui->preAddr14lineEdit->setText(QString::number((int)addr));
            break;
        case 14:
            ui->preType15lineEdit->setText(QString::number((int)type));
            ui->preAddr15lineEdit->setText(QString::number((int)addr));
            break;
        case 15:
            ui->preType16lineEdit->setText(QString::number((int)type));
            ui->preAddr16lineEdit->setText(QString::number((int)addr));
            break;
        default:
            break;
    }

}

/*设置流量计参数*/
void Widget::set_flow(int num,char type,char addr)
{
    //char temp[2]={'\0','\0'};
    switch (num)
    {
        case 0:
            ui->flowType1lineEdit->setText(QString::number((int)type));
            ui->flowAddr1lineEdit->setText(QString::number((int)addr));
            break;
        case 1:
            ui->flowType2lineEdit->setText(QString::number((int)type));
            //temp[0]=addr;
            ui->flowAddr2lineEdit->setText(QString::number((int)addr));
            break;
        case 2:
            ui->flowType3lineEdit->setText(QString::number((int)type));
            ui->flowAddr3lineEdit->setText( QString::number((int)addr) );
            break;
        case 3:
            ui->flowType4lineEdit->setText( QString::number((int)type) );
            ui->flowAddr4lineEdit->setText( QString::number((int)addr) );
            break;
        case 4:
            ui->flowType5lineEdit->setText( QString::number((int)type) );
            ui->flowAddr5lineEdit->setText( QString::number((int)addr) );
            break;
        case 5:
            ui->flowType6lineEdit->setText( QString::number((int)type) );
            ui->flowAddr6lineEdit->setText( QString::number((int)addr)  );
            break;
        case 6:
            ui->flowType7lineEdit->setText( QString::number((int)type) );
            ui->flowAddr7lineEdit->setText( QString::number((int)addr) );
            break;
        case 7:
            ui->flowType8lineEdit->setText( QString::number((int)type) );
            ui->flowAddr8lineEdit->setText( QString::number((int)addr) );
            break;
        case 8:
            ui->flowType9lineEdit->setText( QString::number((int)type) );
            ui->flowAddr9lineEdit->setText( QString::number((int)addr) );
            break;
        case 9:
            ui->flowType10lineEdit->setText( QString::number((int)type) );
            ui->flowAddr10lineEdit->setText( QString::number((int)addr) );
            break;
        case 10:
            ui->flowType11lineEdit->setText( QString::number((int)type) );
            ui->flowAddr11lineEdit->setText( QString::number((int)addr) );
            break;
        case 11:
            ui->flowType12lineEdit->setText( QString::number((int)type) );
            ui->flowAddr12lineEdit->setText( QString::number((int)addr) );
            break;
        case 12:
            ui->flowType13lineEdit->setText( QString::number((int)type) );
            ui->flowAddr13lineEdit->setText( QString::number((int)addr) );
            break;
        case 13:
            ui->flowType14lineEdit->setText( QString::number((int)type) );
            ui->flowAddr14lineEdit->setText( QString::number((int)addr) );
            break;
        case 14:
            ui->flowType15lineEdit->setText( QString::number((int)type) );
            ui->flowAddr15lineEdit->setText( QString::number((int)addr) );
            break;
        case 15:
            ui->flowType16lineEdit->setText( QString::number((int)type) );
            ui->flowAddr16lineEdit->setText( QString::number((int)addr) );
            break;
        default:
            break;
    }

}


/*设置截断阀参数*/
void Widget::set_blo(int num,char type,char addr)
{
    switch (num)
    {
        case 0:
            ui->bloType1lineEdit->setText(QString::number((int)type));
            ui->bloAddr1lineEdit->setText(QString::number((int)addr));
            break;
        case 1:
            ui->bloType2lineEdit->setText(QString::number((int)type));
            //temp[0]=addr;
            ui->bloAddr2lineEdit->setText(QString::number((int)addr));
            break;
        case 2:
            ui->bloType3lineEdit->setText(QString::number((int)type));
            ui->bloAddr3lineEdit->setText( QString::number((int)addr) );
            break;
        case 3:
            ui->bloType4lineEdit->setText( QString::number((int)type) );
            ui->bloAddr4lineEdit->setText( QString::number((int)addr) );
            break;
        case 4:
            ui->bloType5lineEdit->setText( QString::number((int)type) );
            ui->bloAddr5lineEdit->setText( QString::number((int)addr) );
            break;
        case 5:
            ui->bloType6lineEdit->setText( QString::number((int)type) );
            ui->bloAddr6lineEdit->setText( QString::number((int)addr)  );
            break;
        case 6:
            ui->bloType7lineEdit->setText( QString::number((int)type) );
            ui->bloAddr7lineEdit->setText( QString::number((int)addr) );
            break;
        case 7:
            ui->bloType8lineEdit->setText( QString::number((int)type) );
            ui->bloAddr8lineEdit->setText( QString::number((int)addr) );
            break;
        case 8:
            ui->bloType9lineEdit->setText( QString::number((int)type) );
            ui->bloAddr9lineEdit->setText( QString::number((int)addr) );
            break;
        case 9:
            ui->bloType10lineEdit->setText( QString::number((int)type) );
            ui->bloAddr10lineEdit->setText( QString::number((int)addr) );
            break;
        case 10:
            ui->bloType11lineEdit->setText( QString::number((int)type) );
            ui->bloAddr11lineEdit->setText( QString::number((int)addr) );
            break;
        case 11:
            ui->bloType12lineEdit->setText( QString::number((int)type) );
            ui->bloAddr12lineEdit->setText( QString::number((int)addr) );
            break;
        case 12:
            ui->bloType13lineEdit->setText( QString::number((int)type) );
            ui->bloAddr13lineEdit->setText( QString::number((int)addr) );
            break;
        case 13:
            ui->bloType14lineEdit->setText( QString::number((int)type) );
            ui->bloAddr14lineEdit->setText( QString::number((int)addr) );
            break;
        case 14:
            ui->bloType15lineEdit->setText( QString::number((int)type) );
            ui->bloAddr15lineEdit->setText( QString::number((int)addr) );
            break;
        case 15:
            ui->bloType16lineEdit->setText( QString::number((int)type) );
            ui->bloAddr16lineEdit->setText( QString::number((int)addr) );
            break;
        default:
            break;
    }

}


/*获取压力计参数*/
void Widget::get_pre(int num,uchar *type,uchar *addr)
{
    bool ok;
    switch (num)
    {
        case 0:
            *type = (uchar)ui->preType1lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr1lineEdit->text().toInt(&ok,10);
            break;
        case 1:
            *type = (uchar)ui->preType2lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr2lineEdit->text().toInt(&ok,10);
            break;
        case 2:
            *type = (uchar)ui->preType3lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr3lineEdit->text().toInt(&ok,10);
            break;
        case 3:
            *type = (uchar)ui->preType4lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr4lineEdit->text().toInt(&ok,10);
            break;
        case 4:
            *type = (uchar)ui->preType5lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr5lineEdit->text().toInt(&ok,10);
            break;
        case 5:
            *type = (uchar)ui->preType6lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr6lineEdit->text().toInt(&ok,10);
            break;
        case 6:
            *type = (uchar)ui->preType7lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr7lineEdit->text().toInt(&ok,10);
            break;
        case 7:
            *type = (uchar)ui->preType8lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr8lineEdit->text().toInt(&ok,10);
            break;
        case 8:
            *type = (uchar)ui->preType9lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr9lineEdit->text().toInt(&ok,10);
            break;
        case 9:
            *type = (uchar)ui->preType10lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr10lineEdit->text().toInt(&ok,10);
            break;
        case 10:
            *type = (uchar)ui->preType11lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr11lineEdit->text().toInt(&ok,10);
            break;
        case 11:
            *type = (uchar)ui->preType12lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr12lineEdit->text().toInt(&ok,10);
            break;
        case 12:
            *type = (uchar)ui->preType13lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr13lineEdit->text().toInt(&ok,10);
            break;
        case 13:
            *type = (uchar)ui->preType14lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr14lineEdit->text().toInt(&ok,10);
            break;
        case 14:
            *type = (uchar)ui->preType15lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr15lineEdit->text().toInt(&ok,10);
            break;
        case 15:
            *type = (uchar)ui->preType16lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->preAddr16lineEdit->text().toInt(&ok,10);
            break;
        default:
            break;
    }
}

/*获取流量计参数*/
void Widget::get_flow(int num,uchar *type,uchar *addr)
{
    bool ok;
    switch (num)
    {
        case 0:
            *type = (uchar)ui->flowType1lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr1lineEdit->text().toInt(&ok,10);
            break;
        case 1:
            *type = (uchar)ui->flowType2lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr2lineEdit->text().toInt(&ok,10);
            break;
        case 2:
            *type = (uchar)ui->flowType3lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr3lineEdit->text().toInt(&ok,10);
            break;
        case 3:
            *type = (uchar)ui->flowType4lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr4lineEdit->text().toInt(&ok,10);
            break;
        case 4:
            *type = (uchar)ui->flowType5lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr5lineEdit->text().toInt(&ok,10);
            break;
        case 5:
            *type = (uchar)ui->flowType6lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr6lineEdit->text().toInt(&ok,10);
            break;
        case 6:
            *type = (uchar)ui->flowType7lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr7lineEdit->text().toInt(&ok,10);
            break;
        case 7:
            *type = (uchar)ui->flowType8lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr8lineEdit->text().toInt(&ok,10);
            break;
        case 8:
            *type = (uchar)ui->flowType9lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr9lineEdit->text().toInt(&ok,10);
            break;
        case 9:
            *type = (uchar)ui->flowType10lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr10lineEdit->text().toInt(&ok,10);
            break;
        case 10:
            *type = (uchar)ui->flowType11lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr11lineEdit->text().toInt(&ok,10);
            break;
        case 11:
            *type = (uchar)ui->flowType12lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr12lineEdit->text().toInt(&ok,10);
            break;
        case 12:
            *type = (uchar)ui->flowType13lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr13lineEdit->text().toInt(&ok,10);
            break;
        case 13:
            *type = (uchar)ui->flowType14lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr14lineEdit->text().toInt(&ok,10);
            break;
        case 14:
            *type = (uchar)ui->flowType15lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr15lineEdit->text().toInt(&ok,10);
            break;
        case 15:
            *type = (uchar)ui->flowType16lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->flowAddr16lineEdit->text().toInt(&ok,10);
            break;
        default:
            break;
    }
}

/*获取截断阀参数*/
void Widget::get_blo(int num,uchar *type,uchar *addr)
{
    bool ok;
    switch (num)
    {
        case 0:
            *type = (uchar)ui->bloType1lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr1lineEdit->text().toInt(&ok,10);
            break;
        case 1:
            *type = (uchar)ui->bloType2lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr2lineEdit->text().toInt(&ok,10);
            break;
        case 2:
            *type = (uchar)ui->bloType3lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr3lineEdit->text().toInt(&ok,10);
            break;
        case 3:
            *type = (uchar)ui->bloType4lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr4lineEdit->text().toInt(&ok,10);
            break;
        case 4:
            *type = (uchar)ui->bloType5lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr5lineEdit->text().toInt(&ok,10);
            break;
        case 5:
            *type = (uchar)ui->bloType6lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr6lineEdit->text().toInt(&ok,10);
            break;
        case 6:
            *type = (uchar)ui->bloType7lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr7lineEdit->text().toInt(&ok,10);
            break;
        case 7:
            *type = (uchar)ui->bloType8lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr8lineEdit->text().toInt(&ok,10);
            break;
        case 8:
            *type = (uchar)ui->bloType9lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr9lineEdit->text().toInt(&ok,10);
            break;
        case 9:
            *type = (uchar)ui->bloType10lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr10lineEdit->text().toInt(&ok,10);
            break;
        case 10:
            *type = (uchar)ui->bloType11lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr11lineEdit->text().toInt(&ok,10);
            break;
        case 11:
            *type = (uchar)ui->bloType12lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr12lineEdit->text().toInt(&ok,10);
            break;
        case 12:
            *type = (uchar)ui->bloType13lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr13lineEdit->text().toInt(&ok,10);
            break;
        case 13:
            *type = (uchar)ui->bloType14lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr14lineEdit->text().toInt(&ok,10);
            break;
        case 14:
            *type = (uchar)ui->bloType15lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr15lineEdit->text().toInt(&ok,10);
            break;
        case 15:
            *type = (uchar)ui->bloType16lineEdit->text().toInt(&ok,10);
            *addr = (uchar)ui->bloAddr16lineEdit->text().toInt(&ok,10);
            break;
        default:
            break;
    }
}

