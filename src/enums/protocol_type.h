/**
  ******************************************************************************
  * @file           : protocol_type.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/14
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_PROTOCOL_TYPE_H
#define SOCKET_TOOLS_PROTOCOL_TYPE_H

#include <netinet/in.h>

enum class ProtocolType : unsigned int {
    IP                                = IPPROTO_IP,
    Icmp                              = IPPROTO_ICMP,
    Igmp                              = IPPROTO_IGMP,
    Ggp                               = IPPROTO_GGP,
    IPv4                              = IPPROTO_IPV4,
    Tcp                               = IPPROTO_TCP,
    Stream                            = IPPROTO_ST,
    EGP                               = IPPROTO_EGP,
    PIGP                              = IPPROTO_PIGP,
    RCCMon                            = IPPROTO_RCCMON,
    NVPII                             = IPPROTO_NVPII,
    Pup                               = IPPROTO_PUP,
    Argus                             = IPPROTO_ARGUS,
    EMCON                             = IPPROTO_EMCON,
    XNet                              = IPPROTO_XNET,
    Chaos                             = IPPROTO_CHAOS,
    Udp                               = IPPROTO_UDP,
    Multiplex                         = IPPROTO_MUX,
    DCNMeas                           = IPPROTO_MEAS,
    HostMonitor                       = IPPROTO_HMP,
    PacketRadioMeas                   = IPPROTO_PRM,
    Idp                               = IPPROTO_IDP,
    Trunk1                            = IPPROTO_TRUNK1,
    Trunk2                            = IPPROTO_TRUNK2,
    Leaf1                             = IPPROTO_LEAF1,
    Leaf2                             = IPPROTO_LEAF2,
    RDP                               = IPPROTO_RDP,
    IRTP                              = IPPROTO_IRTP,
    Tp                                = IPPROTO_TP,
    Bulk                              = IPPROTO_BLT,
    NetworkServices                   = IPPROTO_NSP,
    MeritInternodal                   = IPPROTO_INP,
    SeqExchange                       = IPPROTO_SEP,
    ThirdParty                        = IPPROTO_3PC,
    InterDomainPolicy                 = IPPROTO_IDPR,
    XTP                               = IPPROTO_XTP,
    DatagramDelivery                  = IPPROTO_DDP,
    ControlMessageTp                  = IPPROTO_CMTP,
    Tpxx                              = IPPROTO_TPXX,
    IL                                = IPPROTO_IL,
    IPv6                              = IPPROTO_IPV6,
    SourceDemandRouting               = IPPROTO_SDRP,
    Ipv6RoutingHeader                 = IPPROTO_ROUTING,
    IPv6FragmentHeader                = IPPROTO_FRAGMENT,
    InterDomain                       = IPPROTO_IDRP,
    ResourceReservation               = IPPROTO_RSVP,
    GeneralRoutingEncap               = IPPROTO_GRE,
    MobileHostRouting                 = IPPROTO_MHRP,
    BHA                               = IPPROTO_BHA,
    IPSecEncapsulatingSecurityPayload = IPPROTO_ESP,
    Ipv6AuthHeader                    = IPPROTO_AH,
    IntegratedNetLayerSecurity        = IPPROTO_INLSP,
    IPWithEncryption                  = IPPROTO_SWIPE,
    NextHopResolution                 = IPPROTO_NHRP,
    IcmpV6                            = IPPROTO_ICMPV6,
    IPv6NoNextHeader                  = IPPROTO_NONE,
    IPv6DestinationOptions            = IPPROTO_DSTOPTS,
    AnyHostInternal                   = IPPROTO_AHIP,
    CFTP                              = IPPROTO_CFTP,
    Hello                             = IPPROTO_HELLO,
    SatnetEXPAK                       = IPPROTO_SATEXPAK,
    Kryptolan                         = IPPROTO_KRYPTOLAN,
    RemoteVirtualDisk                 = IPPROTO_RVD,
    PluribusPacketCore                = IPPROTO_IPPC,

};


#endif //SOCKET_TOOLS_PROTOCOL_TYPE_H
