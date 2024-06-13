/**
  ******************************************************************************
  * @file           : address_family.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/13
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_ADDRESS_FAMILY_H
#define SOCKET_TOOLS_ADDRESS_FAMILY_H

#include <sys/socket.h>

/*
 * 指定 Socket 类的实例可以使用的寻址方案
 */
enum class AddressFamily : unsigned int {
    Unspecified     = AF_UNSPEC,            /* 未指定的地址族 */
    Unix            = AF_UNIX,              /* Unix 本地到主机地址 */
    InterNetwork    = AF_INET,              /* IP 版本 4 的地址 (UDP, TCP, etc.) */
    ImpLink         = AF_IMPLINK,           /* ARPANET IMP 地址 */
    Pup             = AF_PUP,               /* PUP 协议的地址 */
    Chaos           = AF_CHAOS,             /* MIT CHAOS 协议的地址 */
    NS              = AF_NS,                /* Xerox NS 协议的地址 */
    Osi             = AF_OSI,               /* OSI 协议的地址 */
    Ecma            = AF_ECMA,              /* 欧洲计算机制造商协会 (ECMA) 地址 */
    DataKit         = AF_DATAKIT,           /* Datakit 协议的地址 */
    Ccitt           = AF_CCITT,             /* CCITT 协议（如 X.25）的地址 */
    Sna             = AF_SNA,               /* IBM SNA 地址 */
    DecNet          = AF_DECnet,            /* DEC net 地址 */
    DataLink        = AF_DLI,               /* 直接数据链接接口地址 */
    HyperChannel    = AF_HYLINK,            /* NSC HyperChannel 地址 */
    AppleTalk       = AF_APPLETALK,         /* AppleTalk 地址 */
    Route           = AF_ROUTE,             /* 内部路由协议的地址 */
    LinkLayer       = AF_LINK,              /* 链路层接口的地址 */
    PseudoXTP       = pseudo_AF_XTP,        /* Xpress 传输层协议的地址 */
    CO_IP           = AF_COIP,              /* 面向连接的 IP 地址，又名 ST II */
    CNT             = AF_CNT,               /* 计算机网络技术 */
    PseudoRTIP      = pseudo_AF_RTIP,       /* 帮助识别 RTIP 数据包 */
    IPX             = AF_IPX,               /* Novell 互联网协议的地址 */
    SIP             = AF_SIP,               /* 小型互联网协议的地址 */
    PseudoPIP       = pseudo_AF_PIP,        /* 帮助识别 PIP 包 */
    NDRV            = AF_NDRV,              /* 网络驱动程序 “raw” 访问 */
    ISDN            = AF_ISDN,              /* 综合业务数字网络的地址 */
    PseudoKey       = pseudo_AF_KEY,        /* 内部密钥管理功能的地址 */
    InterNetworkV6  = AF_INET6,             /* IP 版本 6 的地址 (UDP, TCP, etc.) */
    NativeATM       = AF_NATM,              /* 本地ATM服务地址 */
    System          = AF_SYSTEM,            /* 内核事件消息 */
    NetBios         = AF_NETBIOS,           /* NetBios 地址 */
    PPP             = AF_PPP,               /* PPP 通讯协议的地址 */
    PseudoHDRCMPLT  = pseudo_AF_HDRCMPLT,   /* BPF 使用它来不重写接口输出例程中的标头 */
    Reserved        = AF_RESERVED_36,       /* 保留供内部使用 */
    IEEE80211       = AF_IEEE80211,         /* IEEE 802.11 协议的地址 */
    VM              = AF_VSOCK,             /* VM 套接字 */
    MAX             = AF_MAX,               /* MAX 地址 */
};

#endif //SOCKET_TOOLS_ADDRESS_FAMILY_H
