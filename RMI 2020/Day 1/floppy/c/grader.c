#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "floppy_c.h"

#define NMAX 100000
#define MMAX 100000
#define BITSMAX 2000000

int subtask_id, N, M;
int *v;
int *sorted_v;
int *a, *b;
int *correct_answers;

// Print score to stdout and exit.
void score_and_exit(const double pts, const char *verdict) {
    fprintf(stderr, "%s", verdict);
    fprintf(stdout, "%f", pts);
    exit(0);
}

// Contestant sent too many bits.
void too_many_bits() {
    score_and_exit(0, "Too many stored bits!");
}

// Contestant did not send any bits.
void misformatted_stored_bits() {
    score_and_exit(0, "Misformatted stored bits or save_to_floppy not called!");
}

// Contestant did not call the answer function.
void answer_not_provided() {
    score_and_exit(0, "Answer not provided!");
}

// Contestant sent a wrong answer.
void wrong_answer() {
    score_and_exit(0, "Wrong answer to query!");
}

// Contestant sent a correct answer.
void correct_answer() {
    score_and_exit(1, "OK!");
}

int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

void read_test() {
    assert(scanf("%d", &subtask_id) == 1);
    assert(scanf("%d%d", &N, &M) == 2);
    assert(1 <= N && N <= NMAX);
    assert(0 <= M && M <= MMAX);
    v = malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        assert(scanf("%d", &v[i]) == 1);
    }

    // Check all values are distinct.
    sorted_v = malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        sorted_v[i] = v[i];
    }
    qsort((void*)sorted_v, N, sizeof(int), cmp);
    for (int i = 0; i + 1 < N; ++i) {
        assert(sorted_v[i] < sorted_v[i + 1]);
    }

    a = malloc(sizeof(int) * M);
    b = malloc(sizeof(int) * M);
    correct_answers = malloc(sizeof(int) * M);
    for (int i = 0; i < M; ++i) {
        assert(scanf("%d%d%d", &a[i], &b[i], &correct_answers[i]) == 3);
        assert(0 <= a[i] && a[i] <= correct_answers[i] &&
              correct_answers[i] <= b[i] && b[i] < N);
    }
}

void save_to_floppy(int L, char* bits) {
    int* contestant_answers = solve_queries(subtask_id, N, L, bits, M, a, b);
    for (int i = 0; i < M; ++i) {
        if (contestant_answers[i] != correct_answers[i]) {
            wrong_answer();
        }
    }
    correct_answer();
    exit(0);
}

int main(int argc, char **argv) {
    // Read input data.
    read_test();

    // Send subtask_id, N, v.
    read_array(subtask_id, N, v);
    
    answer_not_provided();
    return 0;
}
