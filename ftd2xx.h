#ifndef FTD2XX_H
#define FTD2XX_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef void* FT_HANDLE;
typedef void* PVOID;
typedef const char* LPCSTR;
typedef void* LPVOID;
typedef BYTE* LPBYTE;
typedef ULONG* PULONG;
typedef DWORD* LPDWORD;
typedef WORD* LPWORD;
typedef UCHAR* PUCHAR;

typedef struct _FT_DEVICE_LIST_INFO_NODE {
    DWORD Flags;
    DWORD Type;
    DWORD ID;
    DWORD LocId;
    CHAR SerialNumber[16];
    CHAR Description[64];
    FT_HANDLE ftHandle;
} FT_DEVICE_LIST_INFO_NODE, *PFT_DEVICE_LIST_INFO_NODE;

#define FT_DEVICE_2232C 4
#define FT_DEVICE_2232H 6
#define FT_DEVICE_4232H 7

#define FT_OPEN_BY_LOCATION 0x0002

#define FT_OK 0

DWORD FT_OpenEx(PVOID pArg1, DWORD Flags, FT_HANDLE *pHandle);
DWORD FT_Close(FT_HANDLE handle);
DWORD FT_Write(FT_HANDLE handle, LPVOID buffer, DWORD size, LPDWORD written);
DWORD FT_Read(FT_HANDLE handle, LPVOID buffer, DWORD size, LPDWORD read);
DWORD FT_ResetDevice(FT_HANDLE handle);
DWORD FT_GetQueueStatus(FT_HANDLE handle, LPDWORD rxBytes);
DWORD FT_SetUSBParameters(FT_HANDLE handle, DWORD inSize, DWORD outSize);
DWORD FT_SetChars(FT_HANDLE handle, UCHAR EventChar, UCHAR EventCharEnabled,
                  UCHAR ErrorChar, UCHAR ErrorCharEnabled);
DWORD FT_SetTimeouts(FT_HANDLE handle, DWORD readTimeout, DWORD writeTimeout);
DWORD FT_SetLatencyTimer(FT_HANDLE handle, UCHAR latency);
DWORD FT_GetLatencyTimer(FT_HANDLE handle, PUCHAR latency);
DWORD FT_SetBitMode(FT_HANDLE handle, UCHAR mask, UCHAR enable);
DWORD FT_CreateDeviceInfoList(LPDWORD numDevs);
DWORD FT_GetDeviceInfoList(PFT_DEVICE_LIST_INFO_NODE list, LPDWORD numDevs);
DWORD FT_GetDeviceInfoDetail(DWORD index, LPDWORD flags, LPDWORD type, LPDWORD id,
                             LPDWORD locId, LPVOID serial, LPVOID desc, FT_HANDLE *handle);
DWORD FT_GetDeviceInfo(FT_HANDLE handle, LPDWORD type, LPDWORD id,
                       char* serial, char* desc, PVOID dummy);
#ifdef __cplusplus
}
#endif
#endif // FTD2XX_H
