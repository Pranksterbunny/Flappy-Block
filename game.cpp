#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = -55.f;
float player_pos_y = 0.f;
float pipe_pos_x = 85.f;
float pipe_pos_y = 55 - (rand()%90);
float pipe_speed = 0.5;
int player_score;
float pipe2_pos_x = pipe_pos_x + 50;
float pipe2_pos_y = 55 - (rand() % 90);
float pipe3_pos_x = pipe2_pos_x + 50;
float pipe3_pos_y = 55 - (rand() % 90);
float pipe4_pos_x = pipe3_pos_x + 50;
float pipe4_pos_y = 55 - (rand() % 90);


internal void
simulate_game(Input* input, float dt) {
	clear_screen(0x000000);
	draw_rect(0, 0, 85, 45, 0xffffff);
	int count = 1;
	float speed = 10.f;
	if (pressed(BUTTON_UP)) player_pos_y += speed;
	if (pressed(BUTTON_DOWN)) player_pos_y -= speed;

	draw_rect(player_pos_x, player_pos_y, 2.5, 2.5, 0x000000);
	draw_rect(pipe_pos_x, (pipe_pos_y - 50), 5, 40, 0x000000);
	draw_rect(pipe_pos_x, (pipe_pos_y + 50), 5, 40, 0x000000);
	
	draw_rect(pipe2_pos_x, (pipe2_pos_y - 50), 5, 40, 0x000000);
	draw_rect(pipe2_pos_x, (pipe2_pos_y + 50), 5, 40, 0x000000);

	draw_rect(pipe3_pos_x, (pipe3_pos_y - 50), 5, 40, 0x000000);
	draw_rect(pipe3_pos_x, (pipe3_pos_y + 50), 5, 40, 0x000000);

	draw_rect(pipe4_pos_x, (pipe4_pos_y - 50), 5, 40, 0x000000);
	draw_rect(pipe4_pos_x, (pipe4_pos_y + 50), 5, 40, 0x000000);

	if (count > 400) {
		pipe_speed += 0.1;
	}

	pipe_pos_x -= pipe_speed;
	player_pos_y -= 0.5; 

	pipe2_pos_x -= pipe_speed;
	pipe3_pos_x -= pipe_speed;
	pipe4_pos_x -= pipe_speed;
	if (pipe_pos_x < -90.0) {
		pipe_pos_x = pipe4_pos_x + 50;
		pipe_pos_y = 55 - (rand() % 90);
	}
	if (pipe2_pos_x < -90.0) {
		pipe2_pos_x = pipe_pos_x + 50;
		pipe2_pos_y = 55 - (rand() % 90);
	}
	if (pipe3_pos_x < -90.0) {
		pipe3_pos_x = pipe2_pos_x + 50;
		pipe3_pos_y = 55 - (rand() % 90);
	}
	if (pipe4_pos_x < -90.0) {
		pipe4_pos_x = pipe3_pos_x + 50;
		pipe4_pos_y = 55 - (rand() % 90);
	}
	if (pipe_pos_y < -35) pipe_pos_y = -35;
	if (pipe2_pos_y < -35) pipe2_pos_y = -35;
	if (pipe3_pos_y < -35) pipe3_pos_y = -35;
	if (pipe4_pos_y < -35) pipe4_pos_y = -35;
	if (pipe_pos_y > 35) pipe_pos_y = 35;
	if (pipe2_pos_y > 35) pipe2_pos_y = 35;
	if (pipe3_pos_y > 35) pipe3_pos_y = 35;
	if (pipe4_pos_y > 35) pipe4_pos_y = 35;
	//scoring
	if (player_pos_x == pipe_pos_x) player_score += 1;
	if (player_pos_x == pipe2_pos_x) player_score += 1;
	if (player_pos_x == pipe3_pos_x) player_score += 1;
	if (player_pos_x == pipe4_pos_x) player_score += 1;
	draw_number(player_score, 0, 40, 1.f, 0x32CD32);
	//collisions
	if (player_pos_y < -42.5) player_pos_y = -42.5;
	if (player_pos_y > 42.5) player_pos_y = 42.5;
	//pipe1
	if ((player_pos_y + 2.5) > (pipe_pos_y + 10) && (player_pos_x + 2.5) > (pipe_pos_x - 5) && (player_pos_x - 2.5) < (pipe_pos_x + 5)){
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);
	}
	if ((player_pos_y - 2.5) < (pipe_pos_y - 10) && (player_pos_x + 2.5) > (pipe_pos_x - 5) && (player_pos_x - 2.5) < (pipe_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);
	}
	//pipe2
	if ((player_pos_y + 2.5) > (pipe2_pos_y + 10) && (player_pos_x + 2.5) > (pipe2_pos_x - 5) && (player_pos_x - 2.5) < (pipe2_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);

	}
	if ((player_pos_y - 2.5) < (pipe2_pos_y - 10) && (player_pos_x + 2.5) > (pipe2_pos_x - 5) && (player_pos_x - 2.5) < (pipe2_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);
	}
	//pipe3
	if ((player_pos_y + 2.5) > (pipe3_pos_y + 10) && (player_pos_x + 2.5) > (pipe3_pos_x - 5) && (player_pos_x - 2.5) < (pipe3_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);

	}
	if ((player_pos_y - 2.5) < (pipe3_pos_y - 10) && (player_pos_x + 2.5) > (pipe3_pos_x - 5) && (player_pos_x - 2.5) < (pipe3_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);
	}
	//pipe4
	if ((player_pos_y + 2.5) > (pipe4_pos_y + 10) && (player_pos_x + 2.5) > (pipe4_pos_x - 5) && (player_pos_x - 2.5) < (pipe4_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);

	}
	if ((player_pos_y - 2.5) < (pipe4_pos_y - 10) && (player_pos_x + 2.5) > (pipe4_pos_x - 5) && (player_pos_x - 2.5) < (pipe4_pos_x + 5)) {
		clear_screen(0x000000);
		draw_text("YOU DIED", -50, 10, 2, 0xffffff);
		end = true;
		draw_text("YOUR SCORE WAS", -50, -10, 1, 0xffffff);
		draw_number(player_score, 40, -13, 2, 0x32CD32);
	}
}