#ifndef SKILLS_C_INCLUDED
#define SKILLS_C_INCLUDED

void runSkills()
{
  //Close claw and drive back
  intakeAndLiftTask_intakeState = INTAKE_REST;
  intakeAndLiftTask_liftState = LIFT_DOWN;
  startTask(intakeAndLiftTask);
  driveStraight(610*3);
}

#endif //SKILLS_C_INCLUDED
