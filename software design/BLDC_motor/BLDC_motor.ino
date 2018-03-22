/**
Copyright (c) 2018, Clément Ronzon
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of BLDC_motor, Arduino-BLDC nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define HALL_U  2
#define HALL_V  3
#define HALL_W  4

#define PHASE_U 8
#define PHASE_V 9
#define PHASE_W 10

#define ENABLE  12

void setup(void) {
  pinMode(HALL_U, INPUT);
  pinMode(HALL_V, INPUT);
  pinMode(HALL_W, INPUT);
  pinMode(PHASE_U, OUTPUT);
  pinMode(PHASE_V, OUTPUT);
  pinMode(PHASE_W, OUTPUT);
  pinMode(ENABLE, OUTPUT);
}

void loop(void) {
  digitalWrite(ENABLE, HIGH);
  writePhases(digitalRead(HALL_U), digitalRead(HALL_V), digitalRead(HALL_W));
  digitalWrite(ENABLE, LOW);
}

void writePhases(bool u, bool v, bool w) {
  bool invert = LOW;
  if (u != v) digitalWrite(PHASE_V, invert^u);
  if (v != w) digitalWrite(PHASE_W, invert^v);
  if (u != w) digitalWrite(PHASE_U, invert^w);
}
