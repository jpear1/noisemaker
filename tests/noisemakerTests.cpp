#include <iostream>
#include <cmath>
#include <vector>
#include "noisemaker.h"
#include "fileFuncs.h"
#include "adder.h"
#include "oscillator.h"
#include "constant.h"
#include "premadeSignals.h"

using namespace std;

int main() {
  noisemaker::sampleRate = 44100;
  double durationInSeconds = 4.0;
  int numSamples = (int) floor(durationInSeconds * noisemaker::sampleRate);
 
  sample samples[numSamples];

  // VIBRATO DEMO:

  Oscillator output = formVibratoSineWave(440, 3, 110, Constant(noisemaker::maxSample));

  // CHORD DEMO

  // Oscillator root = formSineWave(440);
  // Oscillator M3 = formSineWave(523);
  // Oscillator P5 = formSineWave(660);
  // Oscillator M7 = formSineWave(784);
  // #define WIS Adder::WeightedInputSignal
  // Adder output({WIS(root, .4), WIS(M3, .1), WIS(P5, .2), WIS(M7, .1)});
  // #undef WIS

  for (int i = 0; i < numSamples; i++) {
    samples[i] = output.step();
  }

  writeWavFile(fopen("test.wav", "w"), samples, numSamples, noisemaker::sampleRate);

  cout << endl;
}