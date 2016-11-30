#ifndef TRAINSENSOR_H_H
#define TRAINSENSOR_H_H

class TrainSensor(){
    private:
        bool state;
    public:
        void getTrainSensorState(){
            return self.state;
        };
        void SendSignal();
        void Graduate();
};

#endif