#include <stdio.h>
#include <time.h>

void Init() {

}
void Update() {

}
void Render() {

}
void Release() {

}

int main(void)
{

	clock_t CurTime, OldTime;
	Init();
	OldTime = clock();

	Init();
	while (1) {
		OldTime = clock();

		Update();
		Render();

		while (1)
		{
			CurTime = clock();
			if (CurTime - OldTime > 33)
				break;
		}
	}
	Release();
	return 0;

}
