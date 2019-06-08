#include "Font.h"

Font * Font::_instance = NULL;

Font::Font()
{
}


Font::~Font()
{
}

Font * Font::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Font();
	}
	return _instance;
}

void Font::Draw(float x, float y, const string & s)
{
	CTexture * texture = CTexture::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(eType::font);
	CGame *mGame = CGame::GetInstance();
	int left, top, right, bottom;
	for (UINT i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int lo = s[i] - 'A';
			
			if (lo < 18)
			{
				left = 2 + lo * 8;
				top = 1;
				right = left + 9;
				bottom = top + 9;
			}
			else
			{
				lo -= 18;
				left = 2 + lo * 8;
				top = 10;
				right = left + 9;
				bottom = top + 9;
			}
			mGame->Draw(x + 4.0f + i*8, y + 4.0f, tex, left, top, right, bottom, 0, D3DXVECTOR2(0, 0), 255);
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int lo = s[i] - '0';
				left = 2 + lo * 8;
				top = 28;
				right = left + 9;
				bottom = top + 9;
				
			}
			else
			{
				left = 58;
				top = 37;
				right = left + 9;
				bottom = top + 9;
			}
		}
		mGame->Draw(x + 4.0f + i * 8, y + 4.0f, tex, left, top, right, bottom, 0, D3DXVECTOR2(0, 0), 255);
			
	}
}
