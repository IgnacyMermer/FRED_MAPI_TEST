#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include "default2.h"
#include "Alfred/print.h"
#include "Parser/utility.h"
//#include "TCM_values.h"
#include <sstream>


Default2::Default2(std::string endpointParam) {
    finalValue = 0;
    endpoint=endpointParam;
}

string Default2::processInputMessage(string input) {
    std::string address="";
    vector<string> parameters = Utility::splitString(input, ",");

    if(endpoint=="VTIME_LOW"){
        address="00000008";
    }
    else if(endpoint=="VTIME_HIGH"){
        address="00000009";
    }
    else if(endpoint=="SC_LEVEL_A"){
        address="0000000A";
    }
    else if(endpoint=="SC_LEVEL_C"){
        address="0000000B";
    }
    else if(endpoint=="C_LEVEL_A"){
        address="0000000C";
    }
    else if(endpoint=="C_LEVEL_C"){
        address="0000000D";
    }
    else if(endpoint=="LASER_DELAY"){
        address="00000002";
    }
    else if(endpoint=="ATTENUATOR"){
        address="00000003";
    }
    else if(endpoint=="EXT_SW"){
        address="00000004";
    }
    else if(endpoint=="BOARD_TEMP"){
        address="00000005";
    }
    else if(endpoint=="TRIGGER5_CNT"){
        address="00000070";
    }
    else if(endpoint=="TRIGGER4_CNT"){
        address="00000071";
    }
    else if(endpoint=="TRIGGER3_CNT"){
        address="00000074";
    }
    else if(endpoint=="TRIGGER2_CNT"){
        address="00000072";
    }
    else if(endpoint=="TRIGGER1_CNT"){
        address="00000073";
    }
    else if(endpoint=="MAIN_PANEL"){
        address="000000E8";
    }
    else if(endpoint=="SIDE_A_STATUS"){
        address="0000001A";
    }
    else if(endpoint=="SIDE_C_STATUS"){
        address="0000003A";
    }
    else if(endpoint=="BKGRND0_CNT"){
        address="00000075";
    }
    else if(endpoint=="BKGRND1_CNT"){
        address="00000076";
    }
    else if(endpoint=="BKGRND2_CNT"){
        address="00000077";
    }
    else if(endpoint=="BKGRND3_CNT"){
        address="00000078";
    }
    else if(endpoint=="BKGRND4_CNT"){
        address="00000079";
    }
    else if(endpoint=="BKGRND5_CNT"){
        address="0000007A";
    }
    else if(endpoint=="BKGRND6_CNT"){
        address="0000007B";
    }
    else if(endpoint=="BKGRND7_CNT"){
        address="0000007C";
    }
    else if(endpoint=="BKGRND8_CNT"){
        address="0000007D";
    }
    else if(endpoint=="BKGRND9_CNT"){
        address="0000007E";
    }
    else if(endpoint=="FPGA_TEMP"){
        address="000000FC";
    }
    else if(endpoint=="1VPOWER"){
        address="000000FD";
    }
    else if(endpoint=="18VPOWER"){
        address="000000FE";
    }
    else if(endpoint=="MODE_SETTINGS"){
        address="000000D8";
    }
    else if(endpoint=="LASER_DIVIDER"){
        address="0000001B";
    }
    else if(endpoint=="TRIGGER_MODES"){
        address="0000000E";
    }
    else if(endpoint=="DS_TRIGGER_MASK"){
        address="000000E4";
    }
    else if(endpoint=="BCID_OFFSET"){
        address="000000E3";
    }
    else if(endpoint=="DG_TRIGGER_MASK"){
        address="000000D9";
    }
    else if(endpoint=="SYSTEM_ID"){
        address="000000E1";
    }
    else if(endpoint=="CRU_ORBIT"){
        address="000000E9";
    }
    else if(endpoint=="CRU_BC"){
        address="000000EA";
    }
    else if(endpoint=="FIFO_COUNT"){
        address="000000EB";
    }
    else if(endpoint=="SEL_FIRST_HIT_DROPPED_ORBIT"){
        address="000000EC";
    }
    else if(endpoint=="SEL_LAST_HIT_DROPPED_ORBIT"){
        address="000000ED";
    }
    else if(endpoint=="SEL_HITS_DROPPED"){
        address="000000EE";
    }
    else if(endpoint=="READOUT_RATE"){
        address="000000EF";
    }
    else if(endpoint=="IPbus_FIFO_DATA"){
        address="000000F0";
    }
    else if(endpoint=="EVENTS_COUNT"){
        address="000000F1";
    }
    else if(endpoint=="MCODE_TIME"){
        address="000000F7";
    }
    else if(endpoint=="FW_TIME"){
        address="000000FF";
    }
    if(endpoint=="TRIGGERS"){
        Print::PrintInfo(input);
    }
    //if (input == ""||input == "set"||(parameters.size()>1&&parameters[1]=="0")){
        sequence = "reset\n0x000"+address+"00000000,write\nread";
    //}
    /*else if(input=="error"){
        this->publishError("Error!");
    }
    else if(parameters[1]=="1"){
        string data="";
        int num = std::stoi(parameters[0]);
        if(endpoint=="SIDE_A_STATUS"){
            if(parameters.size()>2&&parameters[2]=="set"){
                std::stringstream ss;
                ss << std::hex << (1 << num);
                std::string hex_str = ss.str();
                data="";
                for(int i=0; i<8-hex_str.length(); i++){
                    data+="0";
                }
                data+=hex_str;
                sequence = "reset\n0x0020000001AFFFFFFFF,write\nread\n0x0030000001A"+data+",write\nread";
            }
            else if(parameters[2]=="clear"){
                int temp = 0xFFFFFFFF;
                temp-=(1 << num);
                std::stringstream ss;
                ss << std::hex << temp;
                data = ss.str();
                sequence = "reset\n0x0020000001A"+data+",write\nread\n0x0030000001A00000000,write\nread";
            }
        }
        else if(endpoint=="SIDE_C_STATUS"){
            if(parameters.size()>2&&parameters[2]=="set"){
                std::stringstream ss;
                ss << std::hex << (1 << num);
                std::string hex_str = ss.str();
                data="";
                for(int i=0; i<8-hex_str.length(); i++){
                    data+="0";
                }
                data+=hex_str;
                sequence = "reset\n0x0020000003AFFFFFFFF,write\nread\n0x0030000003A"+data+",write\nread";
            }
            else if(parameters[2]=="clear"){
                int temp = 0xFFFFFFFF;
                temp-=(1 << num);
                std::stringstream ss;
                ss << std::hex << temp;
                data = ss.str();
                sequence = "reset\n0x0020000003A"+data+",write\nread\n0x0030000003A00000000,write\nread";
            }
        }
        else if(endpoint=="TRIGGER_MODES"){
            if(parameters.size()>2&&parameters[2]=="set"){
                std::stringstream ss;
                ss << std::hex << (1 << num);
                std::string hex_str = ss.str();
                data="";
                for(int i=0; i<8-hex_str.length(); i++){
                    data+="0";
                }
                data+=hex_str;
                sequence = "reset\n0x0020000000EFFFFFFFF,write\nread\n0x0030000000E"+data+",write\nread";
            }
            else if(parameters[2]=="clear"){
                int temp = 0xFFFFFFFF;
                temp-=(1 << num);
                std::stringstream ss;
                ss << std::hex << temp;
                data = ss.str();
                sequence = "reset\n0x0020000000E"+data+",write\nread\n0x0030000000E00000000,write\nread";
            }
            Print::PrintInfo(sequence);
        }
        else{
            if(parameters[0].length()>2&&parameters[0].substr(0,2)=="0x"){
                parameters[0]=parameters[0].substr(2);
                data+=parameters[0];
                
                int num = std::stoi(data);

                std::stringstream ss;
                ss << std::hex << num;
                std::string hex_str = ss.str();
                for(int i=0; i<8-hex_str.length(); i++){
                    data+="0";
                }
                data+=hex_str;
                this->publishAnswer(data);
            }
            else{
                int num = std::stoi(parameters[0]);
                std::stringstream ss;
                ss << std::hex << num;
                std::string hex_str = ss.str();
                for(int i=0; i<8-hex_str.length(); i++){
                    data+="0";
                }
                data+=hex_str;
                this->publishAnswer(data);
            }
            sequence = "reset\n0x001"+address+data+",write\nread";
        }*/
        //this->publishAnswer(data);
        /*if(endpoint!="SIDE_A_STATUS"&&endpoint!="SIDE_C_STATUS"&&endpoint!="TRIGGER_MODES"){
            this->publishAnswer(data);
            sequence = "reset\n0x001"+address+data+",write\nread"; 
            Print::PrintInfo("write sequence:");
            Print::PrintInfo(sequence);
        }
    }*/
    return sequence;
}

string Default2::processOutputMessage(string output) {
  string value;
    return output;
  try {
    output.erase(remove(output.begin(), output.end(), '\n'), output.end());
    value = output.substr(output.size() - 8, output.size());
    return value;
    finalValue = stoll(value, nullptr, 16);
    //finalValue = stoi(value, nullptr, 16);
    if(endpoint=="FPGA_TEMP"){
        return std::to_string(finalValue * 503.975 / 65536 - 273.15);
    }
    else if(endpoint=="1VPOWER"){
        return std::to_string(finalValue * 3 / 65536.0);
    }
    else if(endpoint=="18VPOWER"){
        return std::to_string(finalValue * 3 / 65536.0);
    }
    //noReturn=false;
  }
  catch (exception &e) {
    Print::PrintInfo(endpoint);
    Print::PrintInfo(e.what());
    Print::PrintError("ERROR in connection with ALF!");
    finalValue=0;
  }

  return to_string(finalValue);
}