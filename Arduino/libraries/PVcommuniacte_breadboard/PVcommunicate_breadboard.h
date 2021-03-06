#ifndef PVcommunicate_breadboard_h
#define PVcommunicate_breadboard_h


#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

//この辺の位置を要調整

//送信側でも受信側からの返信をみたい
//analogread 3
#define CT_SIGNAL 3

//聞き手になればひとまず省略化
/*
#define VOLTAGE A1
#define TEMPERATURE A2
#define LED_TX A3
#define LED_RX A4
*/

//digital write 9
#define L_DRIVE 9
//digital write for disconnect relay swwitch
#define relay 8

//IDはとりあえず1で固定させる
/*
#define SW_BIT0 4
#define SW_BIT1 5
#define SW_BIT2 6
#define SW_BIT3 7
#define SW_BIT4 8
#define SW_BIT5 9
*/


//command list こういう書き方でいいのか
#define DataReq 		1
#define syn 				2
#define communicate 3
#define Ltica 			4
#define DataResp 		5
#define ack 				6
#define Error 			7
#define resend			8
// add command
#define disconnect	9
#define recovery		10


#define PULSE_DRIVE_DURATION    200
#define PULSE_ZERO_DURATION     800
#define PULSE_ONE_DURATION     1600
#define PULSE_BREAK_DURATION   5000

//決め打ちよりはn++して最後にその長さを見る方が賢い気がする これだと固定長

class PV{
public:
  void ltica();
  void getstatus();
	void decidecommand();
	void setcommand(byte command);
  void sendPacket(int length);
  void resvPacket();
	//debug
  void showstatus();
	void createpacket();
	void init();
	int getlpacket();
	void showpacket();
	//確認用

private:
	//全部こうして持たせる必要はあるのか？
  byte ID;
  byte dist_ID;
  byte voltage;
  byte temperature;
	byte _command;
	// std::vector<byte> send_packet;
	// std::vector<byte> resp_packet;
	//可変長にしたいけどひとまず保留
	byte packet[20];
	//再送用にsend recv 分断
	byte sendpacket[20];
	int lpacket = 2;
	int bit_index = 0;
	//コメント表示用
	int sig=0;
	int psig=0;
	byte this_bit=0;
	byte n_recv_packet=0;
	int duration_counter=0;
};

#endif
