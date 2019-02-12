#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNAME 20
#define PLAYERSIZE 20

struct player {
    char first[MAXNAME];
    char last[MAXNAME];
    unsigned int atbats, hits, walks, rbis;
    float battingaverage;
}

void get_batting_average(struct player * players);
void show_team_data(const struct player * players, int n);

int main(void)
{
    struct player players[PLAYERSIZE];
    for (int i = 0; i < PLAYERSIZE; i++)
        players[i] = (struct player) {
            "", "", 0, 0, 0, 0, 0
        };
    FILE * fp;
    int number;
    char first[MAXNAME];
    char last[MAXNAME];
    unsigned int atbats, hits, walks, rbits;

    if ((fp = fopen("player.txt", "r")) == NULL)
    {
        fprintf(stderr, "Could not open file 'player.txt'.\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%d %s %s %u %u %u %u", &number, first, last, &atbats, &hits, &walks, &rbits) == 7)
    {
        if (players[number].first[0] == '\0')
        {
            strncpy(players[number].first, first, MAXNAME);
            strncpy(players[number].last, last, MAXNAME);
        }
        players[number].atbats += atbats;
        players[number].hits += hits;
        players[number].walks += walks;
        players[number].rbits += rbits;
    }

    // calculate batting average
    for (int i = 0; i < PLAYERSIZE; i++)
    {
        get_batting_average(&players[i]);
    }

    fclose(fp);
}

void get_batting_average(struct player * players)
{
    players->battingaverage = players->hits / (float) players->atbats;
}

void show_team_data(const struct player * players, int n)
{
    unsigned int atbats = 0, hits = 0; walks = 0, rbits = 0;
    printf("Team statistics (number, first, last, at bats, hits, walks,"
		   " rbis, average):\n");
    for (int i = 0; i < n; i++, players++)
    {
        printf("%2d ", i);
        printf("%*s %*s %u %u %u %u %.3f\n", NAMELEN, players->first, NAMELEN,
		       players->last, players->atbats, players->hits, players->walks,
		       players->rbis, players->battingaverage);

		atbats += players->atbats;
		hits += players->hits;
		walks += players->walks,
		rbis += players->rbis;
    }
    printf("Combined stats: %u %u %u %u %.3f\n", atbats, hits, walks, rbis,
		   hits / (float) atbats);
}