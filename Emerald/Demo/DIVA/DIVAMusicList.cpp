#include "DIVAHelper.h"
#if _DIVA_
#include "DIVAMusicList.h"

#include <Shlobj.h>
#include <iostream>
#include <string>

DIVAMusicList::DIVAMusicList()
{

}

bool DIVAMusicList::Initialize()
{
	return GetMusicList();
}

bool DIVAMusicList::GetMusicList()
{
	HANDLE fileHandle;
	WIN32_FIND_DATAA data;
	string path = "/Song/*.*";
	fileHandle = FindFirstFileA(path.c_str(), &data);
	if (fileHandle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (data.cFileName[0] == '.')
				continue;

			// �ļ���
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// wfd.cFileName
				cout << "�ļ��У�" << data.cFileName << endl;
			}
			else
			{
				cout << "�ļ���" << data.cFileName << endl;
			}
		} while (FindNextFileA(fileHandle, &data));

		return false;
	}
	return false;
}

#endif