/*
 * File: HdaVerbs.h
 *
 * Copyright (c) 2018 John Davis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EFI_HDA_VERBS_H_
#define _EFI_HDA_VERBS_H_

#include "AudioDxe.h"

// Root node ID.
#define HDA_NID_ROOT    0

// Macros for building verbs.
#define HDA_CODEC_VERB_4BIT(Verb, Payload)  ((((UINT32)Verb) << 16) | (Payload & 0xFFFF))
#define HDA_CODEC_VERB_12BIT(Verb, Payload) ((((UINT32)Verb) << 8) | (Payload & 0xFF))

//
// "Get" Verbs.
//
#define HDA_VERB_GET_CONVERTER_FORMAT           0xA   // Get Converter Format.
#define HDA_VERB_GET_AMP_GAIN_MUTE              0xB   // Get Amplifier Gain/Mute.
#define HDA_VERB_GET_PROCESSING_COEFFICIENT     0xC   // Get Processing Coefficient.
#define HDA_VERB_GET_COEFFICIENT_INDEX          0xD   // Get Coefficient Index.

#define HDA_VERB_GET_PARAMETER                  0xF00 // Get Parameter.
#define HDA_VERB_GET_CONN_SELECT_CONTROL        0xF01 // Get Connection Select Control.
#define HDA_VERB_GET_CONN_LIST_ENTRY            0xF02 // Get Connection List Entry.
#define HDA_VERB_GET_PROCESSING_STATE           0xF03 // Get Processing State.
#define HDA_VERB_GET_INPUT_CONV_SDI_SELECT      0xF04 // Get Input Converter SDI Select.
#define HDA_VERB_GET_POWER_STATE                0xF05 // Get Power State.
#define HDA_VERB_GET_CONVERTER_STREAM_CHANNEL   0xF06 // Get Converter Stream, Channel.
#define HDA_VERB_GET_PIN_WIDGET_CONTROL         0xF07 // Get Pin Widget Control.
#define HDA_VERB_GET_UNSOL_RESPONSE             0xF08 // Get Unsolicited Response.
#define HDA_VERB_GET_PIN_SENSE                  0xF09 // Get Pin Sense.
#define HDA_VERB_GET_BEEP_GENERATION            0xF0A // Get Beep Generation.
#define HDA_VERB_GET_EAPD_BTL_ENABLE            0xF0C // Get EAPD/BTL Enable.
#define HDA_VERB_GET_DIGITAL_CONV_CONTROL       0xF0D // Get Digital Converter Control.
#define HDA_VERB_GET_VOLUME_KNOB                0xF0F // Get Volume Knob.

#define HDA_VERB_GET_GPI_DATA                   0xF10 // Get GPI Data.
#define HDA_VERB_GET_GPI_WAKE_ENABLE_MASK       0xF11 // Get GPI Wake Enable Mask.
#define HDA_VERB_GET_GPI_UNSOL_ENABLE_MASK      0xF12 // Get GPI Unsolicited Enable Mask.
#define HDA_VERB_GET_GPI_STICK_MASK             0xF13 // Get GPI Sticky Mask.
#define HDA_VERB_GET_GPO_DATA                   0xF14 // Get GPO Data.
#define HDA_VERB_GET_GPIO_DATA                  0xF15 // Get GPIO Data.
#define HDA_VERB_GET_GPIO_ENABLE_MASK           0xF16 // Get GPIO Enable Mask.
#define HDA_VERB_GET_GPIO_DIRECTION             0xF17 // Get GPIO Direction.
#define HDA_VERB_GET_GPIO_WAKE_ENABLE_MASK      0xF18 // Get GPIO Wake Enable Mask.
#define HDA_VERB_GET_GPIO_UNSOL_ENABLE_MASK     0xF19 // Get GPIO Unsolicited Enable Mask.
#define HDA_VERB_GET_GPIO_STICKY_MASK           0xF1A // Get GPIO Sticky Mask.
#define HDA_VERB_GET_CONFIGURATION_DEFAULT      0xF1C // Get Configuration Default.

#define HDA_VERB_GET_IMPLEMENTATION_ID          0xF20 // Get Implementation Identification.
#define HDA_VERB_GET_STRIPE_CONTROL             0xF24 // Get Stripe Control.
#define HDA_VERB_GET_CONVERTER_CHANNEL_COUNT    0xF2D // Get Converter Channel Count.
#define HDA_VERB_GET_DATA_ISLAND_PACKET_SIZE    0xF2E // Get Data Island Packet - Size Info.
#define HDA_VERB_GET_EDID_LIKE_DATA             0xF2F // Get EDID-Like Data (ELD).
#define HDA_VERB_GET_DATA_ISLAND_PACKET_INDEX   0xF30 // Get Data Island Packet - Index.
#define HDA_VERB_GET_DATA_ISLAND_PACKET_DATA    0xF31 // Get Data Island Packet – Data.
#define HDA_VERB_GET_DATA_ISLAND_PACKET_XMIT    0xF32 // Get Data Island Packet – Transmit Control.
#define HDA_VERB_GET_CP_CONTROL                 0xF33 // Get Content Protection Control (CP_CONTROL).
#define HDA_VERB_GET_ASP_MAPPING                0xF34 // Get ASP Channel Mapping.

//
// "Set" Verbs.
//
#define HDA_VERB_SET_CONVERTER_FORMAT           0x2   // Set Converter Format.
#define HDA_VERB_SET_AMP_GAIN_MUTE              0x3   // Set Amplifier Gain/Mute.
#define HDA_VERB_SET_PROCESSING_COEFFICIENT     0x4   // Set Processing Coefficient.
#define HDA_VERB_SET_COEFFICIENT_INDEX          0x5   // Set Coefficient Index.

#define HDA_VERB_SET_CONN_SELECT_CONTROL        0x701 // Set Connection Select Control.
#define HDA_VERB_SET_PROCESSING_STATE           0x703 // Set Processing State.
#define HDA_VERB_SET_INPUT_CONV_SDI_SELECT      0x704 // Set Input Converter SDI Select.
#define HDA_VERB_SET_POWER_STATE                0x705 // Set Power State.
#define HDA_VERB_SET_CONVERTER_STREAM_CHANNEL   0x706 // Set Converter Stream, Channel.
#define HDA_VERB_SET_PIN_WIDSET_CONTROL         0x707 // Set Pin Widget Control.
#define HDA_VERB_SET_UNSOL_RESPONSE             0x708 // Set Unsolicited Response.
#define HDA_VERB_SET_PIN_SENSE                  0x709 // Set Pin Sense.
#define HDA_VERB_SET_BEEP_GENERATION            0x70A // Set Beep Generation.
#define HDA_VERB_SET_EAPD_BTL_ENABLE            0x70C // Set EAPD/BTL Enable.
#define HDA_VERB_SET_DIGITAL_CONV_CONTROL1      0x70D // Set Digital Converter Control 1.
#define HDA_VERB_SET_DIGITAL_CONV_CONTROL2      0x70E // Set Digital Converter Control 2.
#define HDA_VERB_SET_VOLUME_KNOB                0x70F // Set Volume Knob.

#define HDA_VERB_SET_GPI_DATA                   0x710 // Set GPI Data.
#define HDA_VERB_SET_GPI_WAKE_ENABLE_MASK       0x711 // Set GPI Wake Enable Mask.
#define HDA_VERB_SET_GPI_UNSOL_ENABLE_MASK      0x712 // Set GPI Unsolicited Enable Mask.
#define HDA_VERB_SET_GPI_STICK_MASK             0x713 // Set GPI Sticky Mask.
#define HDA_VERB_SET_GPO_DATA                   0x714 // Set GPO Data.
#define HDA_VERB_SET_GPIO_DATA                  0x715 // Set GPIO Data.
#define HDA_VERB_SET_GPIO_ENABLE_MASK           0x716 // Set GPIO Enable Mask.
#define HDA_VERB_SET_GPIO_DIRECTION             0x717 // Set GPIO Direction.
#define HDA_VERB_SET_GPIO_WAKE_ENABLE_MASK      0x718 // Set GPIO Wake Enable Mask.
#define HDA_VERB_SET_GPIO_UNSOL_ENABLE_MASK     0x719 // Set GPIO Unsolicited Enable Mask.
#define HDA_VERB_SET_GPIO_STICKY_MASK           0x71A // Set GPIO Sticky Mask.
#define HDA_VERB_SET_CONFIGURATION_DEFAULT0     0x71C // Set Configuration Default Byte 0.
#define HDA_VERB_SET_CONFIGURATION_DEFAULT1     0x71D // Set Configuration Default Byte 1.
#define HDA_VERB_SET_CONFIGURATION_DEFAULT2     0x71E // Set Configuration Default Byte 2.
#define HDA_VERB_SET_CONFIGURATION_DEFAULT3     0x71F // Set Configuration Default Byte 3.

#define HDA_VERB_SET_IMPLEMENTATION_ID          0x720 // Set Implementation Identification.
#define HDA_VERB_SET_STRIPE_CONTROL             0x724 // Set Stripe Control.
#define HDA_VERB_SET_CONVERTER_CHANNEL_COUNT    0x72D // Set Converter Channel Count.
#define HDA_VERB_SET_DATA_ISLAND_PACKET_INDEX   0x730 // Set Data Island Packet - Index.
#define HDA_VERB_SET_DATA_ISLAND_PACKET_DATA    0x731 // Set Data Island Packet – Data.
#define HDA_VERB_SET_DATA_ISLAND_PACKET_XMIT    0x732 // Set Data Island Packet – Transmit Control.
#define HDA_VERB_SET_CP_CONTROL                 0x733 // Set Content Protection Control (CP_CONTROL).
#define HDA_VERB_SET_ASP_MAPPING                0x734 // Set ASP Channel Mapping.
#define HDA_VERB_SET_DIGITAL_CONV_CONTROL3      0x73E // Set Digital Converter Control 3.
#define HDA_VERB_SET_DIGITAL_CONV_CONTROL4      0x73F // Set Digital Converter Control 4.

#define HDA_VERB_FUNC_RESET                     0x7FF // Function Reset.

//
// Parameters for HDA_VERB_GET_PARAMETER.
//
#define HDA_PARAMETER_VENDOR_ID                 0x00 // Vendor ID.
#define HDA_PARAMETER_REVISION_ID               0x02 // Revision ID.
#define HDA_PARAMETER_SUBNODE_COUNT             0x04 // Subordinate Node Count.
#define HDA_PARAMETER_FUNC_GROUP_TYPE           0x05 // Function Group Type.
#define HDA_PARAMETER_FUNC_GROUP_CAPS           0x08 // Audio Function Group Capabilities.
#define HDA_PARAMETER_WIDGET_CAPS               0x09 // Audio Widget Capabilities.
#define HDA_PARAMETER_SUPPORTED_PCM_SIZE_RATES  0x0A // Sample Size, Rate CAPs.
#define HDA_PARAMETER_SUPPORTED_STREAM_FORMATS  0x0B // Stream Formats.
#define HDA_PARAMETER_PIN_CAPS                  0x0C // Pin Capabilities.
#define HDA_PARAMETER_AMP_CAPS_INPUT            0x0D // Input Amp Capabilities.
#define HDA_PARAMETER_CONN_LIST_LENGTH          0x0E // Connection List Length.
#define HDA_PARAMETER_SUPPORTED_POWER_STATES    0x0F // Supported Power States.

#define HDA_PARAMETER_PROCESSING_CAPS           0x10 // Processing Capabilities.
#define HDA_PARAMETER_GPIO_COUNT                0x11 // GPIO Count.
#define HDA_PARAMETER_AMP_CAPS_OUTPUT           0x12 // Output Amp Capabilities.
#define HDA_PARAMETER_VOLUME_KNOB_CAPS          0x13 // Volume Knob Capabilities.

// Packed structures.
// See https://stackoverflow.com/a/28091428.
#pragma pack(1)

//
// Control structures.
//

// Amplifier Gain/Mute Get Payload.
typedef struct {
    UINT8 Index : 4;
    UINT8 Zero1 : 4;
    UINT8 Zero2 : 5;
    UINT8 Channel : 1;
    UINT8 Zero3 : 1;
    UINT8 Amp : 1;
} HDA_VERB_GET_AMP_GAIN_MUTE_PAYLOAD;
#define HDA_AMP_GAIN_MUTE_CHANNEL_RIGHT 0
#define HDA_AMP_GAIN_MUTE_CHANNEL_LEFT  1
#define HDA_AMP_GAIN_MUTE_AMP_INPUT     0
#define HDA_AMP_GAIN_MUTE_AMP_OUTPUT    1

// Amplifier Gain/Mute Get Response.
typedef struct {
    UINT8 Gain : 7;
    BOOLEAN Mute : 1;
    UINT8 Zero1;
    UINT16 Zero2;
} HDA_VERB_GET_AMP_GAIN_MUTE_RESPONSE;

// Amplifier Gain/Mute Set Payload.
typedef struct {
    UINT8 Gain : 7;
    BOOLEAN Mute : 1;
    UINT8 Index : 4;
    BOOLEAN Right : 1;
    BOOLEAN Left: 1;
    BOOLEAN Input : 1;
    BOOLEAN Output : 1;
} HDA_VERB_SET_AMP_GAIN_MUTE_PAYLOAD;

// PinCntl format.
typedef struct {
    UINT8 Vref : 3;
    UINT8 Reserved : 2;
    BOOLEAN InEnabled : 1;
    BOOLEAN OutEnabled : 1;
    BOOLEAN HeadphoneAmpEnable : 1;
    UINT8 Zero1;
    UINT16 Zero2;
} HDA_VERB_PIN_WIDGET_CONTROL_FORMAT;

// EAPD/BTL Enable format.
typedef struct {
    BOOLEAN BalancedIo : 1;
    BOOLEAN Eapd : 1;
    BOOLEAN LeftRightSwap : 1;
    UINT8 Reserved1 : 5;
    UINT16 Reserved2;
} HDA_VERB_EAPD_BTL_ENABLE_FORMAT;

// Volume Knob format.
typedef struct {
    UINT8 Volume : 7;
    BOOLEAN Direct : 1;
    UINT8 Zero1;
    UINT16 Zero2;
} HDA_VERB_VOLUME_KNOB_FORMAT;

//
// Configuration Default format.
//
typedef struct {
    UINT8 Sequence : 4;
    UINT8 DefaultAssociaton : 4;
    UINT8 Misc : 4;
    UINT8 Color : 4;
    UINT8 ConnectionType : 4;
    UINT8 DefaultDevice : 4;
    UINT8 LocationSpecific : 4;
    UINT8 LocationSurface : 2;
    UINT8 PortConnectivity : 2;
} HDA_VERB_CONFIGURATION_DEFAULT_FORMAT;

// Configuration Default misc.
#define HDA_CONFIG_DEFAULT_MISC_JACK_DETECT_OVERRIDE 0x1;

// Configuration Default color.
#define HDA_CONFIG_DEFAULT_COLOR_UNKNOWN    0x0
#define HDA_CONFIG_DEFAULT_COLOR_BLACK      0x1
#define HDA_CONFIG_DEFAULT_COLOR_GREY       0x2
#define HDA_CONFIG_DEFAULT_COLOR_BLUE       0x3
#define HDA_CONFIG_DEFAULT_COLOR_GREEN      0x4
#define HDA_CONFIG_DEFAULT_COLOR_RED        0x5
#define HDA_CONFIG_DEFAULT_COLOR_ORANGE     0x6
#define HDA_CONFIG_DEFAULT_COLOR_YELLOW     0x7
#define HDA_CONFIG_DEFAULT_COLOR_PURPLE     0x8
#define HDA_CONFIG_DEFAULT_COLOR_PINK       0x9
#define HDA_CONFIG_DEFAULT_COLOR_WHITE      0xE
#define HDA_CONFIG_DEFAULT_COLOR_OTHER      0xF

// Configuration Default connection type.
#define HDA_CONFIG_DEFAULT_CONN_UNKNOWN         0x0
#define HDA_CONFIG_DEFAULT_CONN_1_8_STEREO      0x1
#define HDA_CONFIG_DEFAULT_CONN_1_4_STEREO      0x2
#define HDA_CONFIG_DEFAULT_CONN_ATAPI           0x3
#define HDA_CONFIG_DEFAULT_CONN_RCA             0x4
#define HDA_CONFIG_DEFAULT_CONN_OPTICAL         0x5
#define HDA_CONFIG_DEFAULT_CONN_DIGITAL_OTHER   0x6
#define HDA_CONFIG_DEFAULT_CONN_ANALOG_OTHER    0x7
#define HDA_CONFIG_DEFAULT_CONN_MULTI_ANALOG    0x8
#define HDA_CONFIG_DEFAULT_CONN_XLR             0x9
#define HDA_CONFIG_DEFAULT_CONN_RJ11            0xA
#define HDA_CONFIG_DEFAULT_CONN_COMBO           0xB
#define HDA_CONFIG_DEFAULT_CONN_OTHER           0xF

// Configuration Default default device.
#define HDA_CONFIG_DEFAULT_DEVICE_LINE_OUT          0x0
#define HDA_CONFIG_DEFAULT_DEVICE_SPEAKER           0x1
#define HDA_CONFIG_DEFAULT_DEVICE_HEADPHONE_OUT     0x2
#define HDA_CONFIG_DEFAULT_DEVICE_CD                0x3
#define HDA_CONFIG_DEFAULT_DEVICE_SPDIF_OUT         0x4
#define HDA_CONFIG_DEFAULT_DEVICE_OTHER_DIGITAL_OUT 0x5
#define HDA_CONFIG_DEFAULT_DEVICE_MODEM_LINE        0x6
#define HDA_CONFIG_DEFAULT_DEVICE_MODEM_HANDSET     0x7
#define HDA_CONFIG_DEFAULT_DEVICE_LINE_IN           0x8
#define HDA_CONFIG_DEFAULT_DEVICE_AUX               0x9
#define HDA_CONFIG_DEFAULT_DEVICE_MIC_IN            0xA
#define HDA_CONFIG_DEFAULT_DEVICE_TELEPHONY         0xB
#define HDA_CONFIG_DEFAULT_DEVICE_SPDIF_IN          0xC
#define HDA_CONFIG_DEFAULT_DEVICE_OTHER_DIGITAL_IN  0xD
#define HDA_CONFIG_DEFAULT_DEVICE_OTHER             0xF

// Configuration Default location.
#define HDA_CONFIG_DEFAULT_LOC_SPEC_NA      0x0
#define HDA_CONFIG_DEFAULT_LOC_SPEC_REAR    0x1
#define HDA_CONFIG_DEFAULT_LOC_SPEC_FRONT   0x2
#define HDA_CONFIG_DEFAULT_LOC_SPEC_LEFT    0x3
#define HDA_CONFIG_DEFAULT_LOC_SPEC_RIGHT   0x4
#define HDA_CONFIG_DEFAULT_LOC_SPEC_TOP     0x5
#define HDA_CONFIG_DEFAULT_LOC_SPEC_BOTTOM  0x6

#define HDA_CONFIG_DEFAULT_LOC_SURF_EXTERNAL    0x0
#define HDA_CONFIG_DEFAULT_LOC_SURF_INTERNAL    0x1
#define HDA_CONFIG_DEFAULT_LOC_SURF_SEPARATE    0x2
#define HDA_CONFIG_DEFAULT_LOC_SURF_OTHER       0x3

// Configuration Default port connectivity.
#define HDA_CONFIG_DEFAULT_PORT_CONN_JACK           0x0
#define HDA_CONFIG_DEFAULT_PORT_CONN_NONE           0x1
#define HDA_CONFIG_DEFAULT_PORT_CONN_FIXED_DEVICE   0x2
#define HDA_CONFIG_DEFAULT_PORT_CONN_INT_JACK       0x3

//
// Paramemter responses for HDA_VERB_GET_PARAMETER.
//

// Response from HDA_PARAMETER_VENDOR_ID.
typedef struct {
    UINT16 DeviceId;
    UINT16 VendorId;
} HDA_VENDOR_ID;

// Response from HDA_PARAMETER_REVISION_ID.
typedef struct {
    UINT8 SteppingId;
    UINT8 RevisionId;
    UINT8 MinRev : 4;
    UINT8 MajRev : 4;
    UINT8 Reserved;
} HDA_REVISION_ID;

// Response from HDA_PARAMETER_SUBNODE_COUNT.
typedef struct {
    UINT8 NodeCount;
    UINT8 Reserved1;
    UINT8 StartNode;
    UINT8 Reserved2;
} HDA_SUBNODE_COUNT;

// Response from HDA_PARAMETER_FUNC_GROUP_TYPE.
typedef struct {
    UINT8 NodeType : 8;
    BOOLEAN UnSolCapable : 1;
    UINT8 Reserved1 : 7;
    UINT16 Reserved2;
} HDA_FUNC_GROUP_TYPE;

#define HDA_FUNC_GROUP_TYPE_AUDIO   0x01
#define HDA_FUNC_GROUP_TYPE_MODEM   0x02

// Response from HDA_PARAMETER_FUNC_GROUP_CAPS.
typedef struct {
    UINT8 OutputDelay : 4;
    UINT8 Reserved1 : 4;
    UINT8 InputDelay : 4;
    UINT8 Reserved2 : 4;
    BOOLEAN BeepGen : 1;
    UINT8 Reserved3 : 7;
    UINT8 Reserved4 : 8;
} HDA_FUNC_GROUP_CAPS;

// Response from HDA_PARAMETER_WIDGET_CAPS.
typedef struct {
    UINT8 ChannelCountLsb : 1;
    BOOLEAN InAmpPresent : 1;
    BOOLEAN OutAmpPresent : 1;
    BOOLEAN AmpParamOverride : 1;
    BOOLEAN FormatOverride : 1;
    BOOLEAN Stripe : 1;
    BOOLEAN ProcessingWidget : 1;
    BOOLEAN UnSolCapable : 1;
    BOOLEAN ConnectionList : 1;
    BOOLEAN Digital : 1;
    BOOLEAN PowerControl : 1;
    BOOLEAN LeftRightSwapped : 1;
    BOOLEAN ContentProtectionSupported : 1;
    UINT8 ChannelCountExt : 3;
    UINT8 Delay : 4;
    UINT8 Type : 4;
    UINT8 Reserved : 8;
} HDA_WIDGET_CAPS;

// Widget types.
#define HDA_WIDGET_TYPE_OUTPUT          0x0
#define HDA_WIDGET_TYPE_INPUT           0x1
#define HDA_WIDGET_TYPE_MIXER           0x2
#define HDA_WIDGET_TYPE_SELECTOR        0x3
#define HDA_WIDGET_TYPE_PIN_COMPLEX     0x4
#define HDA_WIDGET_TYPE_POWER           0x5
#define HDA_WIDGET_TYPE_VOLUME_KNOB     0x6
#define HDA_WIDGET_TYPE_BEEP_GEN        0x7
#define HDA_WIDGET_TYPE_VENDOR          0xF

// Response from HDA_PARAMETER_SUPPORTED_PCM_SIZE_RATES.
typedef struct {
    BOOLEAN Hz8000 : 1;
    BOOLEAN Hz11025 : 1;
    BOOLEAN Hz16000 : 1;
    BOOLEAN Hz22050 : 1;
    BOOLEAN Hz32000 : 1;
    BOOLEAN Hz44100 : 1;
    BOOLEAN Hz48000 : 1;
    BOOLEAN Hz88200 : 1;
    BOOLEAN Hz96000 : 1;
    BOOLEAN Hz176400 : 1;
    BOOLEAN Hz192000 : 1;
    BOOLEAN Hz384000 : 1;
    UINT8 Reserved1 : 4;

    BOOLEAN Bits8 : 1;
    BOOLEAN Bits16 : 1;
    BOOLEAN Bits20 : 1;
    BOOLEAN Bits24 : 1;
    BOOLEAN Bits32 : 1;
    UINT8 Reserved2 : 3;
    UINT8 Reserved3 : 8;
} HDA_SUPPORTED_PCM_SIZE_RATES;

// Response from HDA_PARAMETER_SUPPORTED_STREAM_FORMATS.
typedef struct {
    BOOLEAN PcmSupported : 1;
    BOOLEAN Float32Supported : 1;
    BOOLEAN Ac3Supported : 1;
    UINT8 Reserved1 : 5;
    UINT8 Reserved2;
    UINT16 Reserved3;
} HDA_SUPPORTED_STREAM_FORMATS;

// Response from HDA_PARAMETER_PIN_CAPS.
typedef struct {
    BOOLEAN ImpedanceSense : 1;
    BOOLEAN TriggerRequired : 1;
    BOOLEAN PresenceDetect : 1;
    BOOLEAN HeadphoneDrive : 1;
    BOOLEAN Output : 1;
    BOOLEAN Input : 1;
    BOOLEAN BalancedIo : 1;
    BOOLEAN Hdmi : 1;
    UINT8 VrefControl : 8;
    BOOLEAN Eapd : 1;
    UINT8 Reserved1 : 7;
    BOOLEAN DisplayPort : 1;
    UINT8 Reserved2 : 2;
    BOOLEAN HighBitRate : 1;
    UINT8 Reserved3 : 4;
} HDA_PIN_CAPS;

// Response from HDA_PARAMETER_AMP_CAPS_INPUT and HDA_PARAMETER_AMP_CAPS_OUTPUT.
typedef struct {
    UINT8 Offset : 7;
    UINT8 Reserved1 : 1;
    UINT8 NumSteps : 7;
    UINT8 Reserved2 : 1;
    UINT8 StepSize : 7;
    UINT8 Reserved3 : 1;
    UINT8 Reserved4 : 7;
    BOOLEAN MuteCapable : 1;
} HDA_AMP_CAPS;

// Response from HDA_PARAMETER_CONN_LIST_LENGTH.
typedef struct {
    UINT8 Length : 7;
    BOOLEAN LongForm : 1;
    UINT8 Reserved1 : 8;
    UINT16 Reserved2 : 16;
} HDA_CONN_LIST_LENGTH;

// Response from HDA_PARAMETER_SUPPORTED_POWER_STATES.
typedef struct {
    BOOLEAN D0Supported : 1;
    BOOLEAN D1Supported : 1;
    BOOLEAN D2Supported : 1;
    BOOLEAN D3Supported : 1;
    BOOLEAN D3ColdSupported : 1;
    UINT8 Reserved1 : 3;
    UINT8 Reserved2 : 8;
    UINT8 Reserved3 : 8;
    UINT8 Reserved4 : 5;
    BOOLEAN S3D3Supported : 1;
    BOOLEAN ClockStop : 1;
    BOOLEAN Epss : 1;
} HDA_SUPPORTED_POWER_STATES;

// Response from HDA_PARAMETER_PROCESSING_CAPS.
typedef struct {
    BOOLEAN Benign : 1;
    UINT8 Zero : 7;
    UINT8 NumCoeff;
    UINT16 Reserved;
} HDA_PROCESSING_CAPS;

// Response from HDA_PARAMETER_GPIO_COUNT.
typedef struct {
    UINT8 NumGpios;
    UINT8 NumGpos;
    UINT8 NumGpis;
    UINT8 Reserved : 6;
    BOOLEAN GpiUnsol : 1;
    BOOLEAN GpiWake : 1;
} HDA_GPIO_COUNT;

// Response from HDA_PARAMETER_VOLUME_KNOB_CAPS.
typedef struct {
    UINT8 NumSteps : 7;
    BOOLEAN Delta : 1;
    UINT8 Reserved1;
    UINT16 Reserved2;
} HDA_VOLUME_KNOB_CAPS;

#pragma pack()

//
// Widget structures.
//
// Generic widget.
typedef struct {
    UINT8 NodeId;
    HDA_WIDGET_CAPS Capabilities;
    UINTN Length;

    UINT8 *ConnectionList;
    UINT8 ConnectionListLength;
    UINT8 ConnectionDefault;
} HDA_WIDGET;

// Input/Output widget.
typedef struct {
    HDA_WIDGET Header;

    HDA_SUPPORTED_PCM_SIZE_RATES SizesRates;
    HDA_SUPPORTED_STREAM_FORMATS StreamFormats;
    HDA_AMP_CAPS AmpCapabilities;
} HDA_WIDGET_INPUT_OUTPUT;

// Pin Complex widget.
typedef struct {
    HDA_WIDGET Header;

    HDA_PIN_CAPS PinCapabilities;
    HDA_AMP_CAPS InAmpCapabilities;
    HDA_AMP_CAPS OutAmpCapabilities;

    HDA_VERB_PIN_WIDGET_CONTROL_FORMAT PinControl;
    HDA_VERB_CONFIGURATION_DEFAULT_FORMAT ConfigurationDefault;
} HDA_WIDGET_PIN_COMPLEX;

// Mixer widget.
typedef struct {
    HDA_WIDGET Header;

    HDA_AMP_CAPS InAmpCapabilities;
    HDA_AMP_CAPS OutAmpCapabilities;
} HDA_WIDGET_MIXER;

// Selector widget.
typedef struct {
    HDA_WIDGET Header;

    HDA_AMP_CAPS InAmpCapabilities;
    HDA_AMP_CAPS OutAmpCapabilities;
} HDA_WIDGET_SELECTOR;

// Power widget.
typedef struct {
    HDA_WIDGET Header;
} HDA_WIDGET_POWER;

// Volume Knob widget.
typedef struct {
    HDA_WIDGET Header;
} HDA_WIDGET_VOLUME_KNOB;

// Beep Generator widget.
typedef struct {
    HDA_WIDGET Header;
} HDA_WIDGET_BEEP_GEN;

typedef struct {
    UINT8 NodeId;
    HDA_FUNC_GROUP_TYPE Type;

    HDA_WIDGET **Widgets;
    UINTN WidgetsLength;
} HDA_FUNC_GROUP;

#endif
