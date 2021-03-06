#ifndef UI_H_
#define UI_H_

#include "gps.h"

#define MIN_VELOCITY_KPH	0
#define MAX_VELOCITY_KPH	999

#define MIN_GLIDE_RATIO		0
#define MAX_GLIDE_RATIO		999

#define MIN_ALTITUDE_M 		-999
#define MAX_ALTITUDE_M 		9999

#define MIN_DISTANCE_M   	0
#define MAX_DISTANCE_M 	   999999

#define MIN_CLIMBRATE_CPS   (-2500)
#define MAX_CLIMBRATE_CPS    (2500)

#define MIN_COMPASS_HEADING		0
#define MAX_COMPASS_HEADING		359

#define FLOAT_DEG(val)  (((float)val)/10000000.0f)
#define RANGE_360(d)  (((d)+360)%360) // 0 - 359 degrees

#define SEL_CLIMB_THRESHOLD         0
#define SEL_ZERO_THRESHOLD          1
#define SEL_SINK_THRESHOLD          2
#define SEL_CROSSOVER_THRESHOLD     3
#define SEL_VARIO_DISPLAY_IIR       4
#define SEL_ACCEL_VAR               5
#define SEL_ZMEAS_VAR               6
#define SEL_UTC_OFFSET              7
#define SEL_BKLIGHT_SECS            8
#define SEL_TRACK_THRESHOLD         9
#define SEL_TRACK_INTERVAL          10
#define SEL_GLIDE_IIR               11
#define SEL_GPS_STABLE_DOP          12
#define SEL_GYRO_OFFSET_MAX         13
#define SEL_MAG_DECLINATION         14
#define SEL_SPKR_VOL                15
#define SEL_LOG_TYPE                16
#define SEL_WPT_RADIUS              17
#define SEL_ALTITUDE_DISPLAY        18


typedef struct TRACK_ {
   int   year;
   int   month;
   int   day;
   int   hour;
   int   minute;
   float startLatdeg;
   float startLondeg;
   int32_t startAltm;
   int32_t maxAltm;
   float maxClimbrateCps;
   float maxSinkrateCps;
   int32_t startTowmS;
   int32_t distanceFromStartm;
   int32_t elapsedHours;
   int32_t elapsedMinutes;
   int     nextWptInx;
} TRACK;



void ui_printPosDOP(int page, int col, int dop);				
void ui_printBatteryStatus(int page, int col, int bV);
void ui_printSpkrStatus(int page, int col, int bAudioEn);
void ui_printAltitude(int page, int col, int32_t nAlt);
void ui_printDistance(int page, int col, int distanceM) ;
void ui_printGlideRatio(int page, int col, int nGr);
void ui_printVelocity(int page, int col, int nVel);
void ui_printClimbRate(int page, int col, int nCps);
void ui_printBearingAnalog(int page, int col, int velkph, int bearing);
void ui_printHeadingAnalog(int page, int col, int velkph, int heading);
void ui_printRealTime(int page, int col, int nHrs, int nMin);
void ui_printTrackTime(int page, int col, int nHrs, int nMin);
void ui_printLongitude(int page, int col, int32_t nLon);
void ui_printLatitude(int page, int col, int32_t nLat);
void ui_updateFlightDisplay(NAV_PVT* pn, TRACK* ptrk);
void ui_printRouteSegment(int page, int col, int start, int end);
int  ui_saveLog(NAV_PVT* pn, TRACK* pTrk);
void ui_calcTrackElapsedTime(int32_t startmS, int32_t currentmS, int32_t* pHrs, int32_t* pMins);
void ui_alarmWaypointReached();
void ui_displayOptions(void);
int  ui_optionsEventHandler(void);
void ui_screenInit();

extern bool IsSpeakerEnabled;
extern bool IsRouteActive;
extern bool IsGpsFixStable;
extern bool IsTrackActive;
extern bool IsLcdBkltEnabled;
extern bool IsLogging;
extern bool IsServer;
extern bool IsFlashDisplayRequired;
extern bool IsGpsHeading;
extern bool EndTrack;

extern volatile float YawDeg;
extern volatile float DisplayClimbrateCps;
extern volatile float KFAltitudeCm;

#endif

