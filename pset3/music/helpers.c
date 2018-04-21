// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    float numerator = fraction[0] - '0';
    float denominator = fraction[2] - '0';

    //convert fraction to 8ths, and return the number of 8ths note lasts for
    //ex 1/2 = 4/8's, 3/4 = 6/8

    return (int)(numerator * (8.0 / denominator));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // printf("%s\n", note);

    //default frequency is A4 (440hz), but going to use C4 since that math seems cleaner
    // float freq = 261.6255653;
    float freq = 440.000;
    //store default octave, note, and modifier
    float defOct = 4;
    //char defNote = 'C';
    //char defMod = '\0';

    //we can't do arithmetic inside of the POW function, so store value outside of it
    float powerFactor;

    //parse note into note & octave
    //note can be either F#4 or F4, need to take both into account
    char letNote = note[0]; //letter note, ex. "C" (vs C#4 as entire note)
    char mod;
    //store octaves as an int so we can use it for some arithmetic
    int octave = 4;
    if (note[2] == '\0') //if no modifier
    {
        mod = '\0';
        octave = note[1] - '0';
    }
    else
    {
        mod = note[1];
        octave = note[2] - '0';
    }
    //printf("Note: %c %c %i\n", letNote, mod, octave);
    //printf("Note: %c\n", mod);
    //multiply freq by num of octave changes
    //so A4 = 440, A5 = 880, A3 = 220
    freq *= pow(2.0, octave - defOct);
    // printf("Octave modified it to: %i\n", (int)round(freq));


    //modify frequency for sharps/flats
    switch (mod)
    {
        case '#'    :
            //eprintf("Sharp!");
            powerFactor = 1.0 / 12.0;
            break;
        case 'b'    :
            //eprintf("Flat!");
            powerFactor = -1.0 / 12.0;
            break;
        case '\0'   :
            //eprintf("Regular!");
            powerFactor = 0.0;
            break;
    }
    //eprintf("%f", powerFactor);
    freq *= pow(2, powerFactor);
    // printf("Modifier modified it to: %i\n", (int)round(freq));
    //determine number of semitones between A4 and received note
    //freq = (2, n/12) * 440 where n is num of semitones between that an A4
    int numSteps = 1;
    //calculate number of steps via note letter
    switch (letNote)
    {
        case 'A' :
            numSteps = 0.0;
            break;
        case 'B' :
            numSteps = 2.0;
            break;
        case 'C' :
            numSteps = -9.0;
            break;
        case 'D' :
            numSteps = -7.0;
            break;
        case 'E' :
            numSteps = -5.0;
            break;
        case 'F' :
            numSteps = -4.0;
            break;
        case 'G' :
            numSteps = -2.0;
            break;

    }
    powerFactor = numSteps / 12.0;
    freq *= pow(2.0, powerFactor);
    // printf("Note letter modified it to: %i\n", (int)round(freq));

    return (int)round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

