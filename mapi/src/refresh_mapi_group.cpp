#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "refresh_mapi_group.h"
#include "Parser/utility.h"
#include "Alfred/print.h"

RefreshMapiGroup::RefreshMapiGroup(Fred* fred)
{
    this->fred = fred;
}

string RefreshMapiGroup::processInputMessage(string input)
{
	vector< pair <string, string> > requests;

	if (input == "go"){
        Print::PrintInfo("go");
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/DELAY_A", "set"));
		requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/DELAY_C", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/VTIME_LOW", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/VTIME_HIGH", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SC_LEVEL_A", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SC_LEVEL_C", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/C_LEVEL_A", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/C_LEVEL_C", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/LASER_DELAY", "set")); //zmieniony
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/ATTENUATOR", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/EXT_SW", "set")); //zmieniony
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BOARD_TEMP", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BOARD_TYPE", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/ACTUAL_VALUES", "set")); //do zmiany
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER5_SIGN", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER4_SIGN", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER3_SIGN", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER2_SIGN", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER1_SIGN", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGERS", "set")); //do zmiany
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER5_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER4_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER3_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER2_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER1_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/MAIN_PANEL", "set")); //do zmiany - E8
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SIDE_A_STATUS", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SIDE_C_STATUS", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND0_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND1_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND2_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND3_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND4_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND5_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND6_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND7_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND8_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BKGRND9_CNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/FPGA_TEMP", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/1VPOWER", "set"));
		requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/18VPOWER", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/MODE_SETTINGS", "set"));
		requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/LASER_DIVIDER", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/TRIGGER_MODES", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/DS_TRIGGER_MASK", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/BCID_OFFSET", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/DG_TRIGGER_MASK", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SYSTEM_ID", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/CRU_ORBIT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/CRU_BC", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/FIFO_COUNT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SEL_FIRST_HIT_DROPPED_ORBIT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SEL_LAST_HIT_DROPPED_ORBIT", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/SEL_HITS_DROPPED", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/READOUT_RATE", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/IPbus_FIFO_DATA", "set"));
        //requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/EVENTS_COUNT", "set"));
        //requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/MCODE_TIME", "set"));
        requests.push_back(make_pair(this->fred->Name()+"/READOUTCARDS/FIT0/EVENTS_COUNT", "set"));
        
		newMapiGroupRequest(requests);
	}
	
	requests.empty();
	
	//noRpcRequest = true;

    return "reset";
}

string RefreshMapiGroup::processOutputMessage(string output)
{
	return output;
}
