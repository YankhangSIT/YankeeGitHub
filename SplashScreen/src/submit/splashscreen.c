#include "cprocessing.h"
#include <stdlib.h>

CP_Image logo;
float currentAlpha = 0;
float renderFaster = 80;
float currentTime = 0;

void splash_screen_init(void)
{
	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);

	CP_System_SetWindowSize(CP_Image_GetWidth(logo), CP_Image_GetHeight(logo));

}

void splash_screen_update(void)
{
	//float currentElapsedTime = CP_System_GetDt();
	
	if (currentTime >= 2) {
		currentTime = 0;
	}
	currentTime += CP_System_GetDt();
	float maxTime = 2;
	float currentAlpha = ((currentTime / maxTime) * 255);

	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

	if (currentAlpha < 255) {
		//logoAlpha += currentElapsedTime*renderFaster;
		CP_Image_Draw(logo, 0.f, 0.f, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo), currentAlpha);

		if (CP_Input_KeyDown(KEY_Q))
		{
			CP_Engine_Terminate();
		}

	}
	else {
		currentAlpha = 0;
	}

	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Graphics_DrawCircle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.0f);
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}
