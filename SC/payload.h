VOID WINAPI ci(int x, int y, int w, int h)
{
    HDC hdc = GetDC(0);
    HRGN hrgn = CreateEllipticRgn(x, y, w + x, h + y);
    SelectClipRgn(hdc, hrgn);
    BitBlt(hdc, x, y, w, h, hdc, x + y, x - y, SRCINVERT);
    DeleteObject(hrgn);
    ReleaseDC(NULL, hdc);
}
DWORD WINAPI ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt(LPVOID lpParam)
{
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    POINT cursor;
    LPCSTR text = 0;

    while (1)
    {
        HDC hdc = GetDC(0);
        GetCursorPos(&cursor);
        int X = cursor.x + rand() % 3 - 1;
        int Y = cursor.y + rand() % 3 - 1;
        SetCursorPos(X, Y);
        SetBkMode(hdc, 0);
        text = "NoEscape8.0.exe (NO SKIDDDDDDD) by MazeIcon & MSAgentRocks324's Imposter";
        SetTextColor(hdc, Hue(239));
        HFONT font = CreateFontA(43, 32, 0, 0, FW_THIN, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "MS Serif");
        SelectObject(hdc, font);
        TextOutA(hdc, cursor.x, cursor.y, text, strlen(text));
        DeleteObject(font);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI shader1(LPVOID lpParam) {
    PRGBTRIPLE rgbtriple; int xxx = 0;
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmi = { 40, w, h, 1, 24 };
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&rgbtriple, 0, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
        for (int i = 0; i < w * h; i++) {
            int x = i % w, y = i / w, t = (x | y);
            rgbtriple[i].rgbtRed += t + x + xxx;
            rgbtriple[i].rgbtGreen *= t + i + xxx;
            rgbtriple[i].rgbtBlue ^= t + y + xxx;
        }
        for (int y = 0; y < h; y++) {
            StretchBlt(hcdc, -13 + rand() % 26, y, w, 1, hcdc, 0, y, w, 1, SRCPAINT);
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCERASE);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); xxx += 5;
    }
    return 0;
}
DWORD WINAPI colourfulpolygonz(LPVOID lpParam) {//they're just triangles lmao =/
    while (true) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HPEN hPen = CreatePen(PS_SOLID, 2, RGB(rand() % 100, 0, 150));
        HPEN hOldPen = SelectPen(hdc, hPen);

        HBRUSH hBrush = CreateSolidBrush(RGB(rand() % 150, 0, 100));
        HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

        POINT vertices[] = { {rand() % w, rand() % h}, {rand() % w, rand() % h}, {rand() % w, rand() % h} };
        Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

        SelectBrush(hdc, hOldBrush);
        DeleteObject(hBrush);

        SelectPen(hdc, hOldPen);
        DeleteObject(hPen);
        ReleaseDC(0, hdc);
        Sleep(1);
    }
    return 0;
}
DWORD WINAPI payload1(LPVOID lpParam) {//something that i can't name it
    while (1) {
        HDC hdc = GetDC(0);
        HDC hdcMem = CreateCompatibleDC(hdc);
        int sw = GetSystemMetrics(0);
        int sh = GetSystemMetrics(1);
        HBITMAP bm = CreateCompatibleBitmap(hdc, sw, sh);
        SelectObject(hdcMem, bm);
        RECT rect;
        GetWindowRect(GetDesktopWindow(), &rect);
        POINT pt[3];
        int inc3 = rand() % 700;
        int v = rand() % 2;
        if (v == 1) inc3 = -700;
        inc3++;
        pt[0].x = rect.left - inc3;
        pt[0].y = rect.top + inc3;
        pt[1].x = rect.right - inc3;
        pt[1].y = rect.top - inc3;
        pt[2].x = rect.left + inc3;
        pt[2].y = rect.bottom - inc3;
        PlgBlt(hdcMem, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        SelectObject(hdc, CreateSolidBrush(RGB(rand() % 666, rand() % 666, rand() % 666)));
        BitBlt(hdc, rand() % 20, rand() % 20, sw, sh, hdcMem, rand() % 20, rand() % 20, SRCINVERT);
        DeleteObject(hdcMem); DeleteObject(bm);
        Sleep(1);
    }
}
DWORD WINAPI shader2(LPVOID lpParam) {
    int xxx = 0;
    while (true) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1), rndsize = 1 + rand() % (h / 2);
        LPVOID MyMemoryAddress = VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); _RGBQUAD* data = (_RGBQUAD*)MyMemoryAddress;
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int yyy = 0; yyy < h; yyy += rndsize) {
            StretchBlt(hcdc, -13 + rand() % 26, yyy, w, rndsize, hcdc, 0, yyy, w, rndsize, NOTSRCCOPY);
        }
        GetBitmapBits(hBitmap, w * h * 4, data);
        for (int i = 0; i < w * h; i++) {
            int x = i % w, y = i / w;
            data[i].r &= i;  data[i].g += i; data[i].b |= i;
            data[i].rgb += 404 ^ (i + xxx + ((x + xxx) ^ (y)));
        }
        SetBitmapBits(hBitmap, w * h * 4, data);
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, NOTSRCERASE);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        VirtualFree(MyMemoryAddress, 0, MEM_RELEASE);
        Sleep(1); xxx += 4;
    }
}
DWORD WINAPI shader3(LPVOID lpParam) {
    float colorShift = 131.3;
    float colorIntensity = 0.13;
    while (1)
    {
        INT i = 0;
        HDC hdc = GetDC(NULL);
        HDC hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        BITMAPINFO bmpi = { 0 };

        bmpi.bmiHeader.biSize = sizeof(bmpi);
        bmpi.bmiHeader.biWidth = w;
        bmpi.bmiHeader.biHeight = h;
        bmpi.bmiHeader.biPlanes = 1;
        bmpi.bmiHeader.biBitCount = 32;
        bmpi.bmiHeader.biCompression = BI_RGB;


        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;

        HBITMAP hBitmap = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hcdc, hBitmap);
        StretchBlt(hcdc, 0, 0, w, h, hdc, 0, 0, w, h, SRCCOPY);

        RGBQUAD rgbquadCopy;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                int index = y * w + x;
                int Xii = x * i & i;
                int Yii = i * y - i;
                int fx = (int)((i * 3) + (i * 6) * sin((Xii + i) + (Yii - i)));

                rgbquadCopy = rgbquad[index];

                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h = fmod(fx / colorShift + y / static_cast<float>(h) * colorIntensity, 1.0f);
                hslcolor.s = fmod(hslcolor.s + (x % 5) / 10.0f, 2.0f);
                hslcolor.l = fmod(hslcolor.l + (y % 5) / 5.0f, 3.0f);
                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }

        i++;

        StretchBlt(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, SRCINVERT);
        ReleaseDC(NULL, hdc);
        ReleaseDC(NULL, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc);
        DeleteDC(hdc);
    }
}
DWORD WINAPI payload2(LPVOID lpParam) {
    while (1) {
        int w = GetSystemMetrics(0); int h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < h; i += 20) {
            StretchBlt(hcdc, rand() % 20, i, w, 20, hcdc, rand() % 20, i, w, 20, NOTSRCCOPY);
        }

        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCINVERT);
        ReleaseDC(0, hdc);
        ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc);
        DeleteDC(hdc);
        Sleep(1);
    }
    return 0;
}
DWORD WINAPI blockz(LPVOID lpParam) {
    int block_w = 13;
    int block_h = 13;
    while (true) {
        int can1 = 1;
        int jia1 = 0; int jia2 = 0;
        int x; int y;
        int x1 = 0; int y1 = 0;
        int x2 = 0; int y2 = 0;
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BOOL bianliang1 = true;
        while (bianliang1) {
            jia1 = jia1 + block_w;
            if (jia1 > w) {
                bianliang1 = false;
            }
            else {
                can1 = can1 + 1;
            }
        }
        can1 = can1 + 1;
        bianliang1 = true;
        int can2 = 1;
        while (bianliang1) {
            jia2 = jia2 + block_h;
            if (jia2 > h) {
                bianliang1 = false;
            }
            else {
                can2 = can2 + 1;
            }
        }
        can2 = can2 + 1;
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int i = 0; i < can2 + 1; i++) {
            for (int k = 0; k < can1 + 1; k++) {
                x = rand() % can1;
                y = i;
                if (x == 1) {
                    x1 = 0;
                }
                else if (x == 2) {
                    x1 = block_w;
                }
                else {
                    x1 = block_w * x - block_w;
                }

                if (y == 1) {
                    y1 = 0;
                }
                else if (y == 2) {
                    y1 = block_h;
                }
                else {
                    y1 = block_h * y - block_h;
                }

                x = rand() % can1;
                y = rand() % can2;
                if (x == 1) {
                    x2 = 0;
                }
                else if (x == 2) {
                    x2 = block_w;
                }
                else {
                    x2 = block_w * x - 1;
                }

                if (y == 1) {
                    y2 = 0;
                }
                else if (y == 2) {
                    y2 = block_h;
                }
                else {
                    y2 = block_h * y - 1;
                }

                StretchBlt(hcdc, x1, y1, block_w, block_h, hcdc, x2, y2, block_w, block_h, NOTSRCCOPY);
            }
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCERASE);
        ReleaseDC(0, hdc);
        ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc);
        DeleteDC(hdc);
        jia1 = 0; jia2 = 0;
        can1 = 0;
        can2 = 0;
        Sleep(500);
    }
    return 0;
}
DWORD WINAPI idk(LPVOID lpParam) {
    srand(time(NULL));
    int size_w = 450, size_h = 270;
    int signX = 1, signY = 1;
    int incrementor = 10;
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    int x = rand() % (w - size_w), y = rand() % (h - size_h);
    while (true) {
        w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        x += incrementor * signX, y += incrementor * signY;
        HDC hdc = GetDC(0);
        StretchBlt(hdc, x, y, size_w, size_h, hdc, 0, 0, w, h, NOTSRCCOPY);
        ReleaseDC(0, hdc);
        DeleteDC(hdc);
        if (y >= h - size_h) { signY = -1; }
        else if (x >= w - size_w) { signX = -1; }
        else if (y <= 0) { signY = 1; }
        else if (x <= 0) { signX = 1; }
        Sleep(1);
    }
    return 0;
}
DWORD WINAPI circlez(LPVOID lpParam) {
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    while (true)
    {
        const int size = 5600;
        int x = w / 2, y = h / 2;

        for (int i = 0; i < size; i += 100)
        {
            ci(x - i / 2, y - i / 2, i, i);
            Sleep(10);
        }
    }
    return 0;
}
DWORD WINAPI shader4(LPVOID lpParam) {
    HDC hdcScreen = GetDC(NULL);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);

    BITMAPINFO bmi = { 0 };
    PRGBQUAD prgbScreen = { 0 };
    HDC hdcTempScreen;
    HBITMAP hbmScreen;

    bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;

    hdcTempScreen = CreateCompatibleDC(hdcScreen);
    hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
    SelectObject(hdcTempScreen, hbmScreen);

    for (int i = 0;; i++) {
        hdcScreen = GetDC(NULL);
        BitBlt(hdcTempScreen, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
        PRGBQUAD prgbTemp = { 0 };
        prgbTemp = prgbScreen;
        for (int i = 0; i < h / 2; i++) {
            for (int j = 0; j < w; j++) {
                prgbScreen[i * w + j].rgb = prgbTemp[(int)((float)(i * w + j) + (float)sqrt((2 * (h / 2) * i - i * i))) % (w * h)].rgb;
            }
        }
        for (i = h / 2; i < h; i++) {
            for (int j = 0; j < w; j++) {
                prgbScreen[i * w + j].rgb = prgbTemp[(int)((float)(i * w + j) + (float)sqrt((2 * (h / 2) * i - i * i))) % (w * h)].rgb;
            }
        }
        Sleep(50);
        BitBlt(hdcScreen, 0, 0, w, h, hdcTempScreen, 0, 0, SRCINVERT);
        ReleaseDC(NULL, hdcScreen);
        DeleteObject(hdcScreen);
        Sleep(10);
    }
}
DWORD WINAPI iconnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn(LPVOID lpParam) {
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);

    HDC hdc = GetDC(0);

    double i;
    double wave;
    int xs;
    int ys;

    while (true) {
        int sel = rand() % 4 + 1;
        wave = 0;
        i = 0;

        if (sel == 1) {
            xs = 0;
            ys = rand() % y;

            for (; xs < x; xs += 3) {
                DrawIcon(hdc, xs, ys + wave * sin(i), LoadIconW(0, IDI_ERROR));
                i += 0.05;
                wave += 0.32;
                Sleep(10);
            }
        }
        else if (sel == 2) {
            xs = x;
            ys = rand() % y;

            for (; xs > 0; xs -= 3) {
                DrawIcon(hdc, xs, ys + wave * sin(i), LoadIconW(0, IDI_APPLICATION));
                i += 0.05;
                wave += 0.32;
                Sleep(10);
            }
        }
        else if (sel == 3) {
            xs = rand() % x;
            ys = 0;

            for (; ys < y; ys += 3) {
                DrawIcon(hdc, xs + wave * sin(i), ys, LoadIconW(0, IDI_INFORMATION));
                i += 0.05;
                wave += 0.32;
                Sleep(10);
            }
        }
        else if (sel == 4) {
            xs = rand() % x;
            ys = y;

            for (; ys > 0; ys -= 3) {
                DrawIcon(hdc, xs + wave * sin(i), ys, LoadIconW(0, IDI_SHIELD));
                i += 0.05;
                wave += 0.32;
                Sleep(10);
            }
        }
    }
}
DWORD WINAPI shader5(LPVOID lpParam) {
    while (true) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmi = { 40, w, h, 1, 24 };
        PRGBQUAD prgbScreen = { 0 };
        bmi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32 };
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&prgbScreen, 0, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int x = 0; x < w; x += 40) {
            for (int y = 0; y < h; y += 40) {
                StretchBlt(hcdc, x, y, 40, 40, hcdc, x, y, 25, 25, SRCPAINT);
            }
        }
        for (int i = 0; i < h; i++) {
            StretchBlt(hcdc, -1 + (rand() % 3), i, w, 1, hcdc, 0, i, w, 1, SRCINVERT);
        }
        BitBlt(hcdc, 0, 0, w, h, hcdc, 20, 0, SRCCOPY);
        BitBlt(hcdc, 0, 0, w, h, hcdc, -w + 20, 0, SRCCOPY);
        for (int i = 0; i < w * h; i++) {
            prgbScreen[i].rgb += i * 2 & i % w | i * 2 & i / h;
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1);
    }
}
DWORD WINAPI shader6(LPVOID lpParam) {
    HDC hdc = GetDC(NULL);
    HDC hdcCopy = CreateCompatibleDC(hdc);
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    BITMAPINFO bmpi = { 0 };
    HBITMAP bmp;

    bmpi.bmiHeader.biSize = sizeof(bmpi);
    bmpi.bmiHeader.biWidth = w;
    bmpi.bmiHeader.biHeight = h;
    bmpi.bmiHeader.biPlanes = 1;
    bmpi.bmiHeader.biBitCount = 32;
    bmpi.bmiHeader.biCompression = BI_RGB;

    RGBQUAD* rgbquad = NULL;
    HSL hslcolor;

    bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
    SelectObject(hdcCopy, bmp);

    INT i = 0;

    while (1)
    {
        hdc = GetDC(NULL);
        StretchBlt(hdcCopy, 0, 0, w, h, hdc, 0, 0, w, h, SRCCOPY);

        RGBQUAD rgbquadCopy;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                int index = y * w + x;

                int fx = (int)((8 ^ i) + ((8 - i) * sqrt(x - 48.0)) + (4 * i) + ((4 * i) * tan(y + 32.0)));

                rgbquad[index].rgbRed += fx;
                rgbquad[index].rgbGreen += fx;
                rgbquad[index].rgbBlue += fx;
            }
        }

        i++;
        StretchBlt(hdc, 0, 0, w, h, hdcCopy, 0, 0, w, h, SRCCOPY);
        ReleaseDC(NULL, hdc); DeleteDC(hdc);
        Sleep(13);
    }

    return 0x00;
}
DWORD WINAPI shader7(LPVOID lpParam) {
    int i = 0;
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmpi = { 0 };
        bmpi.bmiHeader = { sizeof(bmpi), w, h, 1, 32, BI_RGB };
        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        RGBQUAD rgbquadCopy;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int index = w * y + x;
                int cx = x - (w / 2), cy = y - (h / 2), zx = (cx * cx), zy = (cy * cy), di = 200 + i;
                int fx = (int)di + (di * tan(sqrt(zx + zy) / 39));
                rgbquadCopy = rgbquad[index];
                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h = fmod(fx / 300.f + y / h * .1f, 1.f);
                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCINVERT);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); i++;
    }
    return 0;
}
DWORD WINAPI shader8(LPVOID lpParam) {
    HBRUSH hBrush; int size = 128;
    while (true) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        BITMAPINFO bmpi = { 0 };
        bmpi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32, BI_RGB };
        RGBQUAD* rgbquad = NULL; HSL hslcolor;
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        RGBQUAD rgbquadCopy;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int index = x * h + y;
                rgbquadCopy = rgbquad[index];
                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h = fmod(0, 0);
                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }
        for (int x = 0; x < w; x += size) {
            for (int y = 0; y < h; y += size) {
                hBrush = CreateSolidBrush(RGB((rand() % 666) * 4, rand() % 333, (rand() % 333) * 8));
                SelectObject(hcdc, hBrush);
                PatBlt(hcdc, x, 0, size, h, PATINVERT);
                DeleteObject(hBrush);
                hBrush = CreateSolidBrush(RGB((rand() % 666) * 4, rand() % 333, (rand() % 333) * 8));
                SelectObject(hcdc, hBrush);
                PatBlt(hcdc, 0, y, w, size, PATINVERT);
                DeleteObject(hBrush);
            }
        }
        for (int x = 0; x < w; x += 50) {
            StretchBlt(hcdc, x, -20 + rand() % 40, 50, h, hcdc, x, 0, 50, h, SRCINVERT);
        }
        for (int y = 0; y < h; y += 50) {
            StretchBlt(hcdc, -20 + rand() % 40, y, w, 50, hcdc, 0, y, w, 50, NOTSRCCOPY);
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hdc); DeleteDC(hcdc);
        Sleep(50);
    }
    return 0;
}
DWORD WINAPI shader9(LPVOID lpParam) {
    int i = 0;
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmpi = { 0 };
        bmpi.bmiHeader = { sizeof(bmpi), w, h, 1, 32, BI_RGB };
        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        RGBQUAD rgbquadCopy;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int index = y * w + x;
                int fx = (int)(x + i) & (y + i);
                rgbquadCopy = rgbquad[index];
                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h += (DOUBLE)(FLOAT)fmod(fx / 500.f, 1.f);
                hslcolor.s = 1.f;
                hslcolor.l = 0.5f;
                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCERASE);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); i += 5;
    }
}
DWORD WINAPI shader10(LPVOID lpParam) {
    HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
    int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
    BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
    PRGBTRIPLE rgbtriple;
    for (;;) {
        desk = GetDC(0);
        HDC deskMem = CreateCompatibleDC(desk);
        HBITMAP scr = CreateDIBSection(desk, &bmi, 0, (void**)&rgbtriple, 0, 0);
        SelectObject(deskMem, scr);
        BitBlt(deskMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
        for (int i = 0; i < sw * sh; i++) {
            int x = i % sw, y = i / sh;
            rgbtriple[i].rgbtRed *= x * y + 5;
            rgbtriple[i].rgbtGreen ^= x * y;
            rgbtriple[i].rgbtBlue += 3;
        }
        BitBlt(desk, 0, 0, sw, sh, deskMem, 0, 0, NOTSRCCOPY);
        ReleaseDC(wnd, desk);
        DeleteDC(desk); DeleteDC(deskMem); DeleteObject(scr); DeleteObject(wnd); DeleteObject(rgbtriple); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&bmi);
    }
}
DWORD WINAPI payload3(LPVOID lpParam) {
    BLENDFUNCTION blf = BLENDFUNCTION{ AC_SRC_OVER, 1, 80, 0 };
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc), hcdc2 = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h), hBitmap2 = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap); SelectObject(hcdc2, hBitmap2);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY); BitBlt(hcdc2, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        StretchBlt(hcdc, 0, 0, w / 2, h / 2, hcdc2, 0, 0, w, h, SRCCOPY);
        StretchBlt(hcdc, w / 2, 0, w / 2, h / 2, hcdc2, 0, 0, w, h, SRCCOPY);
        StretchBlt(hcdc, 0, h / 2, w / 2, h / 2, hcdc2, 0, 0, w, h, SRCCOPY);
        StretchBlt(hcdc, w / 2, h / 2, w / 2, h / 2, hcdc2, 0, 0, w, h, SRCCOPY);
        BitBlt(hcdc, 0, 0, w, h, hcdc, 0, 0, SRCINVERT);
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blf);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc); ReleaseDC(0, hcdc2);
        DeleteObject(hBitmap); DeleteObject(hBitmap2);
        DeleteDC(hcdc); DeleteDC(hcdc2); DeleteDC(hdc);
        Sleep(13);
    }
}
DWORD WINAPI payload3num1(LPVOID lpParam) {
    srand(time(NULL));
    int mode = 2;
    int block_w = 240;
    int block_h = 240;
    while (true) {
        int can1 = 1;
        int jia1 = 0; int jia2 = 0;
        int x; int y;
        int x1 = 0; int y1 = 0;
        int x2 = 0; int y2 = 0;
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BOOL bianliang1 = true;
        while (bianliang1) {
            jia1 = jia1 + block_w;
            if (jia1 > w) {
                bianliang1 = false;
            }
            else {
                can1 = can1 + 1;
            }
        }
        can1 = can1 + 1;
        bianliang1 = true;
        int can2 = 1;
        while (bianliang1) {
            jia2 = jia2 + block_h;
            if (jia2 > h) {
                bianliang1 = false;
            }
            else {
                can2 = can2 + 1;
            }
        }
        can2 = can2 + 1;
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int i = 0; i < can2 + 1; i++) {
            for (int k = 0; k < can1 + 1; k++) {
                x = rand() % can1;
                y = i;
                if (x == 1) {
                    x1 = 0;
                }
                else if (x == 2) {
                    x1 = block_w;
                }
                else {
                    x1 = block_w * x - block_w;
                }

                if (y == 1) {
                    y1 = 0;
                }
                else if (y == 2) {
                    y1 = block_h;
                }
                else {
                    y1 = block_h * y - block_h;
                }

                x = rand() % can1;
                y = rand() % can2;
                if (x == 1) {
                    x2 = 0;
                }
                else if (x == 2) {
                    x2 = block_w;
                }
                else {
                    x2 = block_w * x - 1;
                }

                if (y == 1) {
                    y2 = 0;
                }
                else if (y == 2) {
                    y2 = block_h;
                }
                else {
                    y2 = block_h * y - 1;
                }

                StretchBlt(hcdc, x1, y1, block_w, block_h, hdc, x2, y2, block_w, block_h, NOTSRCCOPY);
            }
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCERASE);
        ReleaseDC(0, hdc);
        DeleteObject(hcdc);
        DeleteObject(hBitmap);
        jia1 = 0; jia2 = 0;
        can1 = 0;
        can2 = 0;
        if (mode == 1) {
            block_w += 1;
            block_h += 1;
        }
        else {
            block_w -= 1;
            block_h -= 1;
        }

        if (block_w < 40) {
            mode = 1;
        }
        else if (block_w > 240) {
            mode = 2;
        }
        else if (block_w == 240) {
            mode = 2;
        }
        Sleep(1);
    }
}