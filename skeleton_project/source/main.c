#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "elevator.h"
#include "FSM.h"
#include "timer.h"




int main(){

    elevio_init();
    
    Elevator *p_elevator=malloc(sizeof(Elevator));
    FSM *p_fsm=malloc(sizeof(FSM));
    Timer *p_timer = malloc(sizeof(Timer));

    setTimer(p_timer);

    elevatorInit(p_elevator);
        
    
    while(1){
         FSMSwitch(p_fsm, p_elevator, p_timer);
    }

    
    free(p_elevator);
    free(p_fsm);
    free(p_timer);
    return 0;
}

/*
printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    while(1){
        int floor = elevio_floorSensor();
        printf("floor: %d \n",floor);while(1)
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }*/
    