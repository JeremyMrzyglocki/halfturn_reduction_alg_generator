# halfturn_reduction_alg_generator

In Fewest Moves Rubik's Cube solving an optional step after reducing the possible states of the cube to the set of domino reduction (DR) (for more information look at my domino-reduction repo), one can go further and reduce further into a set called "half-turn-reduction" (HTR) which can be interpreted as a kind of special triple-axis-domino-reduction. This means that on opposite sides there are only two sticker colors each.

In November 2022, I programmed this table-generator that brute-forces all possible 8-move-algorithms and saves the algorithm together with a string of state-describing numbers, and the inverse solution into a big array that is printed out into the console. I might work on this further or merge it with my domino-reduction-alg-generator and a post-HTR solver and a scramble->DR solver to build a very efficient full scramble Rubik's Cube solver.
