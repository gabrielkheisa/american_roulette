#include <iostream>

#include <math.h>

#include <stdlib.h>

int e;

int one, zero;
int variable;
int nambeh;

using namespace std;

//randomizer
float rand_FloatRange(float a, float b) {
  return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

//odd, 0 and 00 excluded
void f_odd(int* var) {
  if (*var % 2 == 0 || *var > 37)
    zero++;
  else
    one++;
}

//even, 0 and 00 excluded
void f_even(int* var) {
  if (*var % 2 == 0 && *var < 37)
    one++;
  else
    zero++;
}


//select number to bet
void f_num(int bet, int* var) {
  if (bet == *var)
    one++;
  else
    zero++;
}

//1st 12, 2nd 12, 3rd 12
//bet = 1 = first 12
//bet = 2 = second 12
//bet = 3 + third 12
void f_1st(int bet, int* var) {
  if (bet == 1) {
    if (*var <= 12) {
      one++;
    } else {
      zero++;
    }
  }

  if (bet == 2) {
    if (*var > 12 && *var <= 24) {
      one++;
    } else {
      zero++;
    }
  }

  if (bet == 3) {
    if (*var > 24 && *var <= 36) {
      one++;
    } else {
      zero++;
    }
  }
}

//first half
f_1to18(int* var) {
  if (*var <= 18)
    one++;
  else
    zero++;
}

//second half
f_19to36(int* var) {
  if (*var > 18 && *var <= 36)
    one++;
  else
    zero++;
}

//number 0 aka. 37
f_0(int* var) {
  if (*var == 37)
    one++;
  else
    zero++;
}

//number 00 aka. 38
f_00(int* var) {
  if (*var == 38)
    one++;
  else
    zero++;
}

int main() {
  int replay = 50; //replay system
  int replay_2 = 1000; //replay game
  int cumulative_win = 0;
  for (int u = 1; u <= replay; u++) {
  BEG:
    one = zero = variable = nambeh = 0;
    for (int i = 1; i <= replay_2; i++) {
      // american roulette, 0 = 37 ; 00 = 38
      variable = round(rand_FloatRange(0.5, 38.5));
      // print result, uncomment to see bet result
      // cout << variable << ",";
      // bet, uncomment "//" one from these :
        f_odd(&variable);
        //f_even(&variable);
        //f_num(5, &variable);
        //f_1st(1, &variable);
        //f_1to18(&variable);
        //f_19to36(&variable);
        //f_0(&variable);
        //f_00(&variable);
    }

  cumulative_win = cumulative_win + one;

  cout << "\n"
       << "lose : " << zero;
  cout << "\nwin : " << one;
  cout << "\n";
  }
  cout << "Average win = " << ((float)cumulative_win/(float)(replay*replay_2));

  cin >> e;
  return 0;
}
