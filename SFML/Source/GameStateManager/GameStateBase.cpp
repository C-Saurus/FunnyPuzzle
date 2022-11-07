#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSPlay1.h"
#include "GSPlay2.h"
#include "GSPlay3.h"
#include "GSPlay4.h"
#include "GSNext.h"
#include "GSNext1.h"
#include "GSNext2.h"
#include "GSNext3.h"
#include "GSEnd.h"
#include "GSSettings.h"
#include "GSAbout.h"
#include "GSUpgrade.h"

GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case PLAY1:
		gs = new GSPlay1();
		break;
	case PLAY2:
		gs = new GSPlay2();
		break;
	case PLAY3:
		gs = new GSPlay3();
		break;
	case PLAY4:
		gs = new GSPlay4();
		break;
	case NEXT:
		gs = new GSNext();
		break;
	case NEXT1:
		gs = new GSNext1();
		break;
	case NEXT2:
		gs = new GSNext2();
		break;
	case NEXT3:
		gs = new GSNext3();
		break;
	case SETTING:
		gs = new GSSettings();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	case UPGRADE:
		gs = new GSUpgrade();
		break;
	case END:
		gs = new GSEnd();
		break;
	default:
		break;
	}
	return gs;
}

