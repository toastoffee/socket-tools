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

/*
 * 指定 Socket 类支持的协议
 */
enum class ProtocolType : int {
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

    /* 55-57: Unassigned */

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
    AnyDistributedFS                  = IPPROTO_ADFS,
    SatnetMonitoring                  = IPPROTO_SATMON,
    VISA                              = IPPROTO_VISA,
    PacketCoreUtility                 = IPPROTO_IPCV,
    CompProtNetExecutive              = IPPROTO_CPNX,
    CompProtHeartBeat                 = IPPROTO_CPHB,
    WangSpanNetwork                   = IPPROTO_WSN,
    PacketVideo                       = IPPROTO_PVP,
    BackroomSatnetMonitoring          = IPPROTO_BRSATMON,
    ND                                = IPPROTO_ND,
    WIDEBANDMonitoring                = IPPROTO_WBMON,
    WIDEBANDEXPAK                     = IPPROTO_WBEXPAK,
    ISOCNLP                           = IPPROTO_EON,
    VMTP                              = IPPROTO_VMTP,
    SecureVMTP                        = IPPROTO_SVMTP,
    BanyonVINES                       = IPPROTO_VINES,
    TTP                               = IPPROTO_TTP,
    NsfNetIGP                         = IPPROTO_IGP,
    DissimilarGateway                 = IPPROTO_DGP,
    TCF                               = IPPROTO_TCF,
    CiscoIGRP                         = IPPROTO_IGRP,
    OSPFIGP                           = IPPROTO_OSPFIGP,
    StriteRPC                         = IPPROTO_SRPC,
    LocusAddressResolution            = IPPROTO_LARP,
    MulticastTransport                = IPPROTO_MTP,
    AX25Frames                        = IPPROTO_AX25,
    EncapsulatedIP                    = IPPROTO_IPEIP,
    MobileIntControl                  = IPPROTO_MICP,
    SemaphoreCommSecurity             = IPPROTO_SCCSP,
    EthernetIPEncapsulation           = IPPROTO_ETHERIP,
    EncapsulationHeader               = IPPROTO_ENCAP,
    AnyPrivateEncryptedScheme         = IPPROTO_APES,
    GMTP                              = IPPROTO_GMTP,

    /* 101-252: Partly Unassigned */
    ProtocolIndependentMcast          = IPPROTO_PIM,
    PayloadCompression                = IPPROTO_IPCOMP,
    PGM                               = IPPROTO_PGM,
    SCTP                              = IPPROTO_SCTP,

    /* 253-254: Experimentation and testing; 255: Reserved (RFC3692) */
    DivertPseudoProtocol              = IPPROTO_DIVERT,
    Raw                               = IPPROTO_RAW,

    MAX                               = IPPROTO_MAX,
    DONE                              = IPPROTO_DONE,
};


#endif //SOCKET_TOOLS_PROTOCOL_TYPE_H
