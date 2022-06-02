#include "LoRaWan_APP.h"

/* This file provides extended functions for original LoraWan102 driver (radio.c) */

void RadioSetTxConfigExt( RadioModems_t modem, int8_t power, uint32_t fdev,
                          uint32_t bandwidth, uint32_t datarate,
                          uint8_t coderate, uint16_t preambleLen,
                          bool fixLen, bool crcOn, bool FreqHopOn,
                          uint8_t HopPeriod, bool iqInverted, uint32_t timeout,
                          uint8_t syncLen, const uint8_t *syncSeq );

void RadioSetRxConfigExt( RadioModems_t modem, uint32_t bandwidth,
                         uint32_t datarate, uint8_t coderate,
                         uint32_t bandwidthAfc, uint16_t preambleLen,
                         uint16_t symbTimeout, bool fixLen,
                         uint8_t payloadLen,
                         bool crcOn, bool freqHopOn, uint8_t hopPeriod,
                         bool iqInverted, bool rxContinuous,
                         uint8_t syncLen, const uint8_t *syncSeq );
