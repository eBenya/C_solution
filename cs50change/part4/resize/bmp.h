/**
 * bmp.h
 *
 * Computer Science 50
 * Problem Set 4
 *
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>

/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct
{
    WORD   bfType;          //The file type. Must be BM(bmp)
    DWORD  bfSize;          //The size, in byte, of the bitmap file.
    WORD   bfReserved1;     //Reserved. must be 0
    WORD   bfReserved2;     //Reserved. must be 0
    DWORD  bfOffBits;       //The offset, in bytes, from the beginning of the BITMAPFILEHEADER struct to the bitmap bits. Смещение в битах до начала изображения.
} __attribute__((__packed__))
BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct
{
    DWORD  biSize;                  //Число байт структуры.
    LONG   biWidth;                 //Ширина битмап в пикселях.
    LONG   biHeight;                //Высота битмап в пикселях.
    WORD   biPlanes;                //Че-то о плоскостях, видать всегда двумерно, потому-то и всегда 1.
    WORD   biBitCount;              //Число бит на 1 пиксль.
    DWORD  biCompression;           //Тип сжатия. Сжать можно только снизу вверх.
    DWORD  biSizeImage;             //Размер картинки в байтах.
    LONG   biXPelsPerMeter;         //Горизонтальное разрешение изображения в пикселях на метр. (Обычно 0)
    LONG   biYPelsPerMeter;         //Вертикальное разрешение изображения в пикселях на метр. (Обычно 0)
    DWORD  biClrUsed;               //Количество используемых цветов. (Обычно 0)
    DWORD  biClrImportant;          //Количество значимых цветов. (Обычно 0)
} __attribute__((__packed__))
BITMAPINFOHEADER;

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
