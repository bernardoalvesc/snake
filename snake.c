#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  
#include <windows.h> 

#define WIDTH 40
#define HEIGHT 20
#define INITIAL_LENGTH 5

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[WIDTH * HEIGHT];
    int length;
    int direction;
} Snake;

void clearScreen() {
 
}

void drawBoard(Snake *snake, Point *food, int score) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {WIDTH + 2, HEIGHT + 2};
    COORD bufferCoord = {0, 0};
    SMALL_RECT writeRegion = {0, 0, WIDTH + 1, HEIGHT + 1};

    CHAR_INFO buffer[(WIDTH + 2) * (HEIGHT + 2)];

 
    for (int i = 0; i < (WIDTH + 2) * (HEIGHT + 2); i++) {
        buffer[i].Char.AsciiChar = ' ';
        buffer[i].Attributes = 0x07; 
    }

  
    for (int x = 0; x < WIDTH + 2; x++) {
        buffer[x].Char.AsciiChar = '#';
    }

    
    for (int x = 0; x < WIDTH + 2; x++) {
        buffer[(HEIGHT + 1) * (WIDTH + 2) + x].Char.AsciiChar = '#';
    }

   
    for (int y = 0; y < HEIGHT; y++) {
        buffer[(y + 1) * (WIDTH + 2)].Char.AsciiChar = '#'; 
        buffer[(y + 1) * (WIDTH + 2) + WIDTH + 1].Char.AsciiChar = '#'; 

        for (int x = 0; x < WIDTH; x++) {
            int index = (y + 1) * (WIDTH + 2) + x + 1;
            int isSnake = 0;
            for (int i = 0; i < snake->length; i++) {
                if (snake->body[i].x == x && snake->body[i].y == y) {
                    buffer[index].Char.AsciiChar = 'O';
                    isSnake = 1;
                    break;
                }
            }
            if (!isSnake) {
                if (food->x == x && food->y == y) {
                    buffer[index].Char.AsciiChar = 'X';
                }
            }
        }
    }

  
    WriteConsoleOutput(hConsole, buffer, bufferSize, bufferCoord, &writeRegion);

  
    COORD cursorPos = {0, HEIGHT + 2};
    SetConsoleCursorPosition(hConsole, cursorPos);
    printf("Pontuacao: %d\n", score);
}

void moveSnake(Snake *snake, int grow) {
    Point nextHead = snake->body[0];
    switch (snake->direction) {
        case 0: nextHead.y--; break;
        case 1: nextHead.x++; break;
        case 2: nextHead.y++; break; 
        case 3: nextHead.x--; break; 
    }
    if (nextHead.x < 0 || nextHead.x >= WIDTH || nextHead.y < 0 || nextHead.y >= HEIGHT) {
        nextHead.x = snake->body[0].x;
        nextHead.y = snake->body[0].y;
    }
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = nextHead;
    if (grow) {
        snake->length++;
    }
}

int checkCollision(Snake *snake) {
    if (snake->body[0].x < 0 || snake->body[0].x >= WIDTH ||
        snake->body[0].y < 0 || snake->body[0].y >= HEIGHT) {
        return 1;
    }
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[i].x == snake->body[0].x && snake->body[i].y == snake->body[0].y) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Snake snake;
    Point food;
    int score = 0;
    int grow = 0;
    int playAgain = 1;

    while (playAgain) {
        // Inicializa a serpente
        snake.length = INITIAL_LENGTH;
        snake.direction = 1; // Começa indo para a direita
        for (int i = 0; i < INITIAL_LENGTH; i++) {
            snake.body[i].x = INITIAL_LENGTH - i - 1;
            snake.body[i].y = 0;
        }

        // Inicializa a comida
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;

        while (1) {
            drawBoard(&snake, &food, score);

            if (checkCollision(&snake)) {
                printf("Voce morreu! Pontuacao: %d\n", score);
                printf("Deseja continuar? (S/N): ");
                char choice = _getch();
                if (choice == 'N' || choice == 'n') {
                    playAgain = 0;
                    break;
                } else {
                    score = 0; 
                    break;
                }
            }

            if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
                score++;
                grow = 1;
                food.x = rand() % WIDTH;
                food.y = rand() % HEIGHT;
            } else {
                grow = 0;
            }

            moveSnake(&snake, grow);

            if (_kbhit()) {
                switch (_getch()) {
                    case 'w': if (snake.direction != 2) snake.direction = 0; break; 
                    case 'd': if (snake.direction != 3) snake.direction = 1; break; 
                    case 's': if (snake.direction != 0) snake.direction = 2; break; 
                    case 'a': if (snake.direction != 1) snake.direction = 3; break; 
                }
            }

            Sleep(100); 
        }
    }

    printf("Obrigado por jogar!\n");
    printf("\nPressione Enter para sair...");
    getchar(); 
    getchar(); 

    return 0;
}
