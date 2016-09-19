#ifndef __CMD_H__
#define __CMD_H__

#include "fdserial.h"

#define CMD_START_BYTE      0xFE
#define CMD_END_BYTE        '\r'

#define CMD_START           "\xFE"
#define CMD_INT8            "\xFD"
#define CMD_UINT8           "\xFC"
#define CMD_INT16           "\xFB"
#define CMD_UINT16          "\xFA"
#define CMD_INT32           "\xF9"
#define CMD_UINT32          "\xF8"
    
#define CMD_HTTP            "\xF7"
#define CMD_WS              "\xF6"
#define CMD_TCP             "\xF5"
#define CMD_STA             "\xF4"
#define CMD_AP              "\xF3"
#define CMD_STA_AP          "\xF2"
    
#define CMD_JOIN            "\xEF"
#define CMD_CHECK           "\xEE"
#define CMD_SET             "\xED"
#define CMD_POLL            "\xEC"
#define CMD_PATH            "\xEB"
#define CMD_SEND            "\xEA"
#define CMD_RECV            "\xE9"
#define CMD_CLOSE           "\xE8"
#define CMD_LISTEN          "\xE7"
#define CMD_ARG             "\xE6"
#define CMD_REPLY           "\xE5"
#define CMD_CONNECT         "\xE4"

#define CMD_END             "\r"

extern fdserial *wifi;
extern fdserial *debug;

void cmd_init(int wifi_rx, int wifi_tx, int debug_rx, int debug_tx);
void request(char *fmt, ...);
void requestPayload(char *buf, int len);
int reply(int chan, int code, char *payload);
int waitFor(char *fmt, ...);
void collectUntil(int term, char *buf, int size);
void collectPayload(char *buf, int bufSize, int count);
void skipUntil(int term);

#endif
