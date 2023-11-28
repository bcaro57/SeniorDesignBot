#ifndef MOTOR_HANDLER_H
#define MOTOR_HANDLER_H


enum class Direction{
        Forward,
        Reverse
};

class MotorDriver{

    public:
        MotorDriver(int _lpwm, int _rpwm, Adafruit_PCF8575* _pcf = NULL);

        void init();
        void setDirection(Direction dir);
        float setSpeed(int percent);
        void setVelocity(int percent);
    private:

        int LPWM;
        int RPWM;
        int speed;

        Direction current_direction;
        Adafruit_PCF8575* PCF;
};

class MotorControl{

    public:
        MotorControl(MotorDriver* _LeftMotor, MotorDriver* _MiddleMotor, MotorDriver* _RightMotor);

        void init();
        void setSpeed(int percent);
        void setMotors(bool LeftOn, bool MiddleOn, bool RightOn);
        void update(uint8_t buf, int MotorState);
    private:

        MotorDriver* LeftMotor;
        MotorDriver* MiddleMotor;
        MotorDriver* RightMotor;

        int speed;

        const int wheelbase_coeff = 1;

};

class Encoder{

    public:
        Encoder(int _pulse_a, int _pulse_b);

        void init();
        static void wheelSpeed();
    private:
        int pulseA;
        int pulseB;
};


#endif