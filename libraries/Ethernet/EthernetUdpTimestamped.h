#ifndef ETHERNETUDPTIMESTAMPED_H
#define ETHERNETUDPTIMESTAMPED_H

#include <EthernetUdp.h>
#include "lwip/udp.h"
#include <lwip/dns.h>
#include "netif/tivaif.h"

class EthernetUDPTimestamped : public EthernetUDP {
public:
	uint32_t getSeconds() { return _p->time_s; }
	uint32_t getNanoseconds() { return _p->time_ns; }
	uint32_t getTxTimestampHi() { return tivaTxTimestampHi; }
	uint32_t getTxTimestampLo() { return tivaTxTimestampLo; }
	// enable or disable transmit timestamping for the current packet
	// the transmit timestamp comes back as a global variable (yes, horrible)
	// tivaTxTimestampLo  tivaTxTimestampHi and also sets
	// tivaTxTimestampDone = true.
	void setTxTimestamp(bool enable) { 
		if (_sendTop == NULL) return;
		if (enable) _sendTop->flags |= PBUF_FLAG_PTP_TXTIMESTAMP; 
		else _sendTop->flags &= ~PBUF_FLAG_PTP_TXTIMESTAMP;
	}
	bool getTxTimestamp() {
		if (_sendTop == NULL) return false;
		if (_sendTop->flags & PBUF_FLAG_PTP_TXTIMESTAMP) return true;
		else return false;
	}
};

#endif
