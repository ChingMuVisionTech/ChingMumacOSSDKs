#include <stdio.h>
//#include <conio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "vrpn_Tracker.h"
#include "vrpn_Button.h"
#include "vrpn_Analog.h"

static bool bPos = true;
static bool bBtn = true;
static bool bAlg = true;
static bool bClk = false;

void VRPN_CALLBACK handle_pos (void *, const vrpn_TRACKERCB t)
{
	static	int	count = 0;

	//fprintf(stderr, ".");
	//if ((++count % 20) == 0) 
	{
		//fprintf(stderr, "\n");
		//if (count > 50) 
		if(bPos)
		{
			printf("Pos, sensor %d = %f, %f, %f, %f, %f, %f, %f\n", t.sensor, t.pos[0], t.pos[1], t.pos[2], t.quat[0], t.quat[1], t.quat[2], t.quat[3]);


			count = 0;
		}
	}
}

void VRPN_CALLBACK handle_btn(void *userdata, const vrpn_BUTTONCB info)
{
	static	int	btnCnt = 0;

	//if ((++btnCnt % 19) == 0) {
		//if (btnCnt > 50) {
		if(bBtn)
			printf("button%d: status:%d\n", info.button, info.state);
			btnCnt = 0;
		//}
	//}
}

void VRPN_CALLBACK handle_analog(void *userdata, const vrpn_ANALOGCB info)
{
	if(!bAlg)
		return;

	printf("analog:");
	for(int i=0; i<info.num_channel; ++i)
	{
		printf("%f\t", info.channel[i]);
	}
	printf("\n");
}

void printHelpMenu()
{
	printf("****************Welcome to use the vrpn test tool*****************\n");
	printf("**input:server_name@server_ip(example:IQTracker_Vrpn@127.0.0.1)\n");
	printf("**tips:\tp--toggle to display 6DOF info\n");
	printf("**\tb--toggle to display button info\n");
	printf("**\ta--toggle to display analog info\n");
	printf("**\th--display this help menu\n");
	printf("**\tx--quit this tool\n");
	printf("**\tp(%d) b(%d) a(%d) d(%d)\n", bPos, bBtn, bAlg, bClk);
	printf("*******************************************************************\n");
}

int startvrpn()
{
	char serverName[256] = {0};
	printHelpMenu();
	printf("please input the server_name@server_ip:");
	

	vrpn_Tracker_Remote tkr(serverName);
	tkr.register_change_handler(NULL, handle_pos);

	vrpn_Button_Remote btn(serverName);
	btn.register_change_handler(NULL, handle_btn);

	vrpn_Analog_Remote analog(serverName);
	analog.register_change_handler(NULL, handle_analog);

	bool bquit = false;
	char inputChar = 0;
	while (!bquit) 
	{
		tkr.mainloop();

		btn.mainloop();

		analog.mainloop();
	}
}
