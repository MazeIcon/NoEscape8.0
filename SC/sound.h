VOID WINAPI sound1() {
	int nSamplesPerSec = 11025, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t * ((t >> t | t >> 13) * 13 & 39)));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound2() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t ^ t >> t));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound3() {
	int nSamplesPerSec = 16000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t / 13 >> (t >> 13) * t / ((t >> 13 & 13) + 13) ^ t + 13));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound4() {
	int nSamplesPerSec = 32000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t * t >> 13 | t >> 13 | t >> 13 ^ t));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound5() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t >> 13 ^ t >> 9 - 1 ^ 1) % 13 * t);
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound6() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t * t >> 13 | t * (t >> 13) | t >> 13));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound7() {
	int nSamplesPerSec = 32000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)(((t % 25) * (t ^ (t * (int)((-559030611 >> ((t >> 10) & 0xA)) & 0xC))) | (t >> 2)));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound8() {
	int nSamplesPerSec = 16000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * ((((((((t / 10) | 0) ^ (((t / 10) | 0) - 1280)) % 11 * t / 2) & 0x7F) + (((((t / 640) | 0) ^ (((t / 640) | 0) - 2)) % 13 * t / 2) & 0x7F)) ^ t)));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound9() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t * (t >> 6 | t >> 13) * 26 & 169));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound10() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 2) * (128 * tan(tan(t / 100) - t / (2 + (t >> 10 & t >> 12) % 9)) + 128));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound11() {
	int nSamplesPerSec = 44100, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (((t / 4 * ((t >> 12 ^ (t >> 12) - 2) % 11) | t >> 13) & 127) + (t / 12 * (0x98646363 >> (t >> 11 & 28) & 15) & 128)));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound12() {
	int nSamplesPerSec = 22050, nSampleCount = nSamplesPerSec * 30;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * (t >> 6 ^ t & t >> 9 ^ t >> 12 | (t << (t >> 6) % 4 ^ -t & -t >> 13) % 128 ^ -t >> 1));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}
VOID WINAPI sound13() {
	int nSamplesPerSec = 8000, nSampleCount = nSamplesPerSec * 45;
	HANDLE hHeap = GetProcessHeap();
	PSHORT psSamples = (PSHORT)HeapAlloc(hHeap, 0, nSampleCount);
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, nSamplesPerSec, nSamplesPerSec, 1, 8, 0 };
	WAVEHDR waveHdr = { (PCHAR)psSamples, nSampleCount, 0, 0, 0, 0, NULL, 0 };
	HWAVEOUT hWaveOut;
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, 0);
	for (INT t = 0; t < nSampleCount; t++) {
		BYTE bFreq = (BYTE)((t % 25) * ((t * 99 / (4 + ((t >> 9) & (t >> 13)))) & (128 * t / 50)));
		((BYTE*)psSamples)[t] = bFreq;
	}
	waveOutPrepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	waveOutWrite(hWaveOut, &waveHdr, sizeof(waveHdr));
	Sleep(nSampleCount * 1000 / nSamplesPerSec);
	while (!(waveHdr.dwFlags & WHDR_DONE)) {
		Sleep(1);
	}
	waveOutReset(hWaveOut);
	waveOutUnprepareHeader(hWaveOut, &waveHdr, sizeof(waveHdr));
	HeapFree(hHeap, 0, psSamples);
}