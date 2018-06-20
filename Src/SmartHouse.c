#include "SmartHouse.h"
#include "String.h"

/*========== GLOBAL VARIABLES ==========*/

const uint8_t   id = 0x05;
const char      ver[11] = "1.0";
const char      name[11] = "�������";
uint8_t         address = 0xFF;
rtc_t rtc = {
    .day = 0, 
    .month = 0, 
    .year = 2000, 
    .hour = 0, 
    .minute = 0, 
    .second = 0
};
int16_t pwr = 0;

meas_t meas[2];
rele_t rele[1];
alrm_t alrm[2];

void smart_init () {
    strcpy (meas[0].name, "����");
    strcpy (meas[0].unit, "�C");
    meas[0].value = 0;
    
    strcpy (meas[1].name, "�����");
    strcpy (meas[1].unit, "%");
    meas[1].value = 0;
    
    strcpy (rele[0].name, "�����");
    rele[0].state &= ~STATE_CONTROL;
    rele[0].state &= ~STATE_STATUS;
    rele[0].state &= ~STATE_SHORT;
    rele[0].state &= ~STATE_FALL;
    
    strcpy (alrm[0].name, "����");
    alrm[0].time.hour = 8;
    alrm[0].time.minute = 0;
    alrm[0].time.second = 0;
    alrm[0].state = STATE_OFF;
    
    strcpy (alrm[1].name, "�����");
    alrm[1].time.hour = 20;
    alrm[1].time.minute = 0;
    alrm[1].time.second = 0;
    alrm[1].state = STATE_OFF;
}