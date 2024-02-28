#include "utils.h"



bool readMsgPkg(struct bufferevent* bev,char* buf,MSGHEAD* msgHeadPtr){
    int pkglen=0;
    int len=msgHeadPtr->len;
    
    while(pkglen!=len){
        int t=bufferevent_read(bev,buf,len-pkglen);
        pkglen+=t;
        buf[t]='\0';
    }
    return true;
}