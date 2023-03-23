
#include "game.hpp"


// enum KeyPressSurfaces
// {
//     KEY_PRESS_SURFACE_DEFAULT,
//     KEY_PRESS_SURFACE_UP,
//     KEY_PRESS_SURFACE_DOWN,
//     KEY_PRESS_SURFACE_LEFT,
//     KEY_PRESS_SURFACE_RIGHT,
//     KEY_PRESS_SURFACE_TOTAL
// };


bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "BingBong's Run", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//
				// iniatialize TTF
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
			}
		}
	}

	return success;
}

bool Game::loadMedia()

{
	cout << "HELLO";
	//Loading success flag
	bool success = true;
	//brokenEgg=loadTexture("Untitled.png");   //loading picture of broken eggs
	//assets = loadTexture("assets.png");
	tFont = TTF_OpenFont("Sans-Bold.ttf", 32);
	cout << TTF_GetError();


    frame[1] = loadTexture("bg.png"); //Level 1 background added
    frame[2] = loadTexture("bg2.png"); //Level 2 background added
	playerI  =loadTexture("player.png");//Player texture added
	barTex = loadTexture("bar.png");//Bar image added
	numberTex =loadTexture("numbers.png");//Number image added
	animalTex =loadTexture("anim.png");//Animal texture added
	carTex =loadTexture("carr.png");//Car texture added
	pigeonTex = loadTexture("pige.png");//pigeon texture added

	//TO DO
	frame[0] = loadTexture("bg.png"); //Instructions background to be added
	rockTex =loadTexture("numbers.png");//rock file to be added


	if(playerI==NULL || frame[level]==NULL || barTex==NULL  || numberTex== NULL || animalTex== NULL || pigeonTex== NULL || carTex== NULL )
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	//loading font file
	
    if (tFont == NULL)
    {
        printf("Failed to load TTF font!\n");
        success = false;
    }

	return success;
}
void Game::drawAllObjects(){

	
	for(auto p: players){
    
		p->draw(gRenderer);
		
	}
	for(auto a: animas){
    
		a->draw(gRenderer);
		
	}
	for(auto c: cars){
    
		c->draw(gRenderer);
		
	}
	for(auto o: ods){
    
		o->draw(gRenderer);
		
	}
	for(auto p: pigu){
    
		p->draw(gRenderer);
		
	}
	for(auto e: eves){
    
		e->draw(gRenderer);
		
	}
	
	
}
void Game:: UpdateScore(){

}
void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(barTex);
	barTex=NULL;
	SDL_DestroyTexture(playerI);
	playerI=NULL;
	SDL_DestroyTexture(numberTex);
	numberTex=NULL;
	SDL_DestroyTexture(frame[level]);
	gTextTexture.Free();
	//Free global font
    TTF_CloseFont( tFont );
    tFont = NULL;
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();


    

    



    
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		//if ()
        //newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}



void Game::run()
{

    SDL_RenderClear(gRenderer);
	//Main loop flag
	bool quit = false;
	//The timer starting time
	
	
    
    // //The timer start/stop flag
    
	//Event handler
	SDL_Event e;
	
	
	bool running = true;
	Player* player;  //pigeon object variable pointer
	SDL_Rect mover={0,550, 50,50}; //position and size of pigeon
	player=new Player(playerI,mover);
	players.push_back(player);
	Score score(tFont);

	//Obstacle *obstacle = NULL;
	
						
	//While application is running
	while( !quit )
	{

		
		/*
		if (level==1){
			obstacles = rand()  %4;
		 	if(delay%100==0){
		 	random=rand() %(800-100-100)+100;
			if(obstacles==0){
		 		SDL_Rect mover={random,300,50,50 }
		 		obstacle=new Bar (bar,mover);
				

		 	}
		 	else if(obstacles==1){
		 		SDL_Rect mover={random,300,50,50 }
		 		obstacle=new animal (animal,mover);
				

		 	}
		 	else if(obstacles==2){
		 		SDL_Rect mover={random,580,50,50 }
		 		obstacle=new car (car,mover);
				

			}
			else if(obstacles==3){
				//random odd numbers 
				SDL_Rect mover={random,300,50,50 }
				obstacle=new odd (,mover);
				

			}

		}
		*/

		if(level ==1){
			//Delay not added yet

			incoming = rand() %100;

			if (incoming <= 25){
				Odd* o;
				SDL_Rect mover = {680, rand()%600, 50, 50};
				o = new Odd(numberTex,mover);

				ods.push_back(o);
			}
			else if(incoming <= 50){
				Even* e;
				SDL_Rect mover = {680, rand()%600, 50, 50};
				e = new Even(numberTex,mover);

				eves.push_back(e);
			}
			else if(incoming <= 70){
				Pigeon* p;
				SDL_Rect mover = {680, rand()%300, 50, 50};
				p = new Pigeon(pigeonTex,mover);

				pigu.push_back(p);
			}
			else if(incoming <= 85){
				Animal* a;
				SDL_Rect mover = {680, (rand()%300) + 300, 50, 50};
				a = new Animal(animalTex,mover);

				animas.push_back(a);
			}else{
				Car* c;
				SDL_Rect mover = {680, (rand()%300) + 300, 50, 50};
				c = new Car(carTex,mover);

				cars.push_back(c);
			}
		}

		else if(level==2){

			incoming = rand()%100;

			/*
		 	if(delay%100==0){
		 		random=rand() %(800-100-100)+100;
			}
			*/
			if(incoming < 70){
				Rock* r;
		 		SDL_Rect mover={rand()%680,300,50,50};
		 		r = new Rock(rockTex,mover);

				rocks.push_back(r);
		 	}
		 	else{
		 		SDL_Rect mover={rand()%680,300,50,50};
		 		//alpha = new Alphabet(alphabetTex,mover);
		 	}
		}

		 
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else{
			//Get the keystates
       		const Uint8 *keystates = SDL_GetKeyboardState(NULL);
			    //If up is pressed
			if( keystates[ SDL_SCANCODE_UP ])
			{
				player->move(U);
			}
		
			//If down is pressed
			if( keystates[ SDL_SCANCODE_DOWN ] )
			{
				player->move(D);
				
			}
		
			//If left is pressed
			if( keystates[ SDL_SCANCODE_LEFT ] && level==2 )
			{
				player->move(L);
				
			}
		
			//If right is pressed
			if( keystates[SDL_SCANCODE_RIGHT ])
			{
				cout << "Hello";
				player->move(R);
			}
			
			}
			
			// if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT)){

			// 	//this is a good location to add pigeon in linked list.
			// 	int xMouse, yMouse;
			// 	SDL_GetMouseState(&xMouse,&yMouse);
				
				
			
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, frame[level], NULL, NULL);//Draws background to renderer
		
		

		
		// updatePigeons();
		// updateEggs();
		drawAllObjects();
		// //draws all objects
		
		// //pi->draw(gRenderer);
		score.draw(gRenderer);
		SDL_RenderPresent(gRenderer); //displays the updated renderer
		SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
		
	}
			

}

