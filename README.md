# Game "Historical battle"

## Legend
You and your army are going to have a fight with opponents team. Your army 
can shoot and go and opponent's army can do the same. You lose, if your army
doesn't have any units at the moment.

## Units

All types of units are created, according to factory pattern, from 
abstract unit class. Armies are created via abstract factory pattern.
Units can be grouped into subdivisions and be like one strong unit.
If artillery loses all it's health points, it becomes a Rocket.

## Regulations

Class Observer is created to regulate all the events on field of play.
It helps armies to know about state of all army and lets each unit to
know about it's state.
Also, there is a Visitor class to regulate any local fights beetween each
pair of units.

## Rules

You have methods "go" and "shoot".
"Shoot": for each unit finds the nearest opponent's one, what is alive at that 
moment, after there is "fight" between them, which regulated via Visitor. 
After some shoots one army loses. Result of game depends on start position 
of each unit, but it generates randomly, so fight is randomly like 
in the real life

## Building

There is CMake file for building this project.