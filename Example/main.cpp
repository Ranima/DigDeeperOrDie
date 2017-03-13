
#include "sfwdraw.h"
#include "GameState.h"
#include "GameOverState.h"


/*
	The main function should be used for application state management.
	Currently, only one state is implemented here, you'll need to add additional
	and get them to behave properly.
*/

void main()
{
	sfw::initContext();

	GameState::Gamestates gamestate = GameState::Gamestates::playing;

	gameOver gameover;
	GameState gs(&gamestate);

	gs.init(); // called once

	gameover.init(); //is
	gameover.play();

	gs.play(); // Should be called each time the state is transitioned into

	while (sfw::stepContext())
	{
		switch (gamestate)
		{
		case GameState::Gamestates::playing:
			gs.step(); // called each update
			gs.draw(); // called each update
			break;
		case GameState::Gamestates::Gameover:
			gameover.step();
			gameover.draw();
			break;
		}
		//gs.step(); // called each update
		//gs.draw(); // called each update

		//gs.next(); Determine the ID of the next state to transition to.
	}

	gs.stop(); // should be called each time the state is transitioned out of

	gs.term(); // called once


	sfw::termContext();

}