#ifndef _NETPACKAGE_H_
#define _NETPACKAGE_H_


#include <stdint.h>

#include "MessageBuffer.h"
#include "IM.Base.pb.h"

typedef struct
{
	uint16_t magic;           //magic number
	uint16_t version;         //protocol version
	uint16_t type;            //protocol type: json, xml, binary, protobuf and so on
	uint16_t len;             //body length
	uint32_t seq;             //message number
	uint16_t sid;             //service id
	uint16_t cid;             //command id
	uint16_t  reserve;        //reserve

}message_head_t;

class Package
{
public:
	Package();
	virtual ~Package() {}

	uint8_t* GetBuffer();
	uint16_t GetLength();
	uint8_t* GetBodyBuffer();
	uint16_t GetBodyLength() { return head.len; }

	uint16_t GetProtocolVersion() { return head.version; }
	uint16_t GetProtocolType() { return head.type; }
	uint32_t GetMessageNumber() { return head.seq; }
	uint16_t GetServiceId() { return head.sid; }
	uint16_t GetCommandId() { return head.cid; }
	uint16_t GetReserved() { return head.reserve; }
	
	bool SetProtocolVersion(uint32_t version) { return head.version = version; }
	bool SetProtocolType(uint32_t type) { return head.type = type; }
	bool SetMessageNumber(uint32_t seq) { return head.seq = seq; }
	bool SetServiceId(uint16_t sid) { return head.sid = sid; }
	bool SetCommandId(uint16_t cid) { return head.cid = cid; }
	bool SetReserved(uint16_t reserve) { return head.reserve = reserve; }

	bool WriteToBody(const char* data);

	bool WriteHeader();

protected:
	MessageBuffer buffer;
	message_head_t head;

};


#endif //_NETPACKAGE_H_
