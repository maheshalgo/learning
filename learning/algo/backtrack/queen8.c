#include <stdio.h>
#include <unistd.h>

int q_mat[8][8]; 


static int 
queen_check_row(int r, int c)
{
    int ic;

    // check if any Q in the row "r"

    for (ic=0; ic<8; ic++) {
        if (ic == c) {
            continue;
        }
        if (q_mat[r][ic]) {
            //printf("Trying Q @ (%d,%d); Row Check Failed @ %d,%d\n", r,c, r,ic);
            return 1;
        }
    }
    //printf("Trying Q @ %d %d ; Row Check passed\n", r,c);
    return 0;
}

static int
queen_check_column(int r, int c)
{
    int ir;

    // check if any Q in the col "c"
    for (ir=0; ir<8; ir++) {
        if (ir == r) {
            continue;
        }
        if (q_mat[ir][c]) {
            //printf("Trying Q @ (%d, %d);   Col Check Failed @ %d,%d\n", 
            //        r,c, ir,c);
            return 1;
        }
    }
    //printf("Trying Q @ %d %d ; Col Check passed\n", r,c);
    return 0;
}

static int
queen_check_diagnal(int r, int c)
{
    int rx, cx, ic;

    // position ptr at the last row or first col (which ever comes first)
    // check that diagnal going from left to right and down to up (viewed
    // as 2 -D map)

    // for this Q @ (r,c) find the row 'rx' in first col (i.e col=0)
    if (c == 0 || r == 7) {
        if (c == 0) { 
            rx = r; cx = c; 
        } else if (r == 7) {
            rx = r; cx = c;
        }
    } else {
        rx = r; cx = c;
        while (rx < 7 && cx != 0) {
            rx++; cx--;
        }
    }

   
    printf("Trying Q @ %d %d ; Left to Right Diag check from %d,%d\n", r,c, rx, cx);
    while (rx >= 0 && cx < 8) {
        if (rx == r && cx == c) {
            rx--; cx++;
            continue;
        }
        if (q_mat[rx--][cx++]) {
            printf("Trying Q @ (%d, %d);  Diag Check Failed @ %d,%d\n", 
                    r,c, rx++,cx--);
            return (1);
        }
    }
    // position ptr at the last row or last col (which ever comes first)
    // check that diagnal going from right to left and down to up (viewed
    // as 2 -D map)
    if (c == 7 || r == 7) {
        if (c == 7) { 
            rx = r; cx = c; 
        } else if (r == 7) {
            rx = r; cx = c;
        }
    } else {
        rx = r; cx = c;
        while (rx < 7 && cx < 7) {
            rx++; cx++;
        }
    }
    printf("Trying Q @ %d %d ; Right to Left Diag check from %d,%d\n", r,c, rx, cx);
    while (rx >= 0 && cx >= 0) {
        if (rx == r && cx == c) {
            rx--; cx--;
            continue;
        }
        if (q_mat[rx--][cx--]) {
            printf("Trying Q @ (%d, %d);  Diag Check Failed @ %d,%d\n", 
                    r,c, rx++,cx++);
            return (1);
        }
    }

    printf("Trying Q @ (%d, %d);  Diag Check Passed \n", r, c);
    return 0;
}


// Implement backtracking to place all 8 Queens

static int
queen_place_at_x_y(int r, int c)
{
    printf("Trying Q @ %d %d\n", r,c);

    if (!q_mat[r][c]) {
        // no Q at this point... check if this is valid position
        if ((!queen_check_row(r, c)) &&
            (!queen_check_column(r, c)) &&
            (!queen_check_diagnal(r, c))) {
            // valid position for Q
            q_mat[r][c]= 1;
            printf("placed Q @ %d, %d\n", r,c);
        } else {
            q_mat[r][c]= 0;
            printf("Failed Q @ %d %d\n", r,c);
        }
    }
    return (q_mat[r][c]);
}


static int
queen_place_all_8(int sr, int sc)
{
    int r, c, ic;


    // if we cannot place Q in this R and any C, then go back 
    // to previous row and change C

    // if we cannot place Q in Row =0, and in any C, STOP
    r = sr; c = sc; // Randomize this
    while (1) {
        if (queen_place_at_x_y(r, c)) {
            // Q placed.. increment row
            r++; c = 0;
            if (r > 7) {
                // Stop ; you found solution
                return (1);
            }
        } else {
            c++;
            // check if we hit last column
            if (c == 8) {
                // need to back track
                // decrement current 'r' and find last 'c' where Q is placed
label:          r--;
                if (r < 0) {
                    // STOP -- no solution
                    return (0);
                } else {
                   ic = 0;
                   while (ic < 8) {
                       if (q_mat[r][ic]) {
                           c = ic;
                           q_mat[r][ic] = 0;
                           printf("Removed Q from %d, %d\n", r,c);
                           break;
                       }
                       ic++;
                   }
                   if (c == 7) {
                       goto label;
                   } else {
                       c++;
                   }
                }
            }
        }
    }
}

int
main(int argc, char *argv[])
{
    int r, c, ic;
    int opt;

    while ((opt = getopt(argc, argv, "r:c:")) != -1) {
        switch (opt) {
            case 'r':
                r = strtol(optarg, NULL, 10);
            break;
            case 'c':
                c = strtol(optarg, NULL, 10);
            break;
            default:
            break;
        }
    }

    printf("%d,%d\n", r,c);
    if (queen_place_all_8(r, c)) {
        for (r = 0; r <8; r++) {
            printf("\n");
            for (c = 0; c < 8; c++) {
                printf("%d ", q_mat[r][c]);
            }
        }
        printf("\n");
    } else {
        printf("No Eight Q solution\n");
    }
}
