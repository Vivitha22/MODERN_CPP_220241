#include<iostream>

enum class SensorType{
    FUEL_GUAGE,
    TYPE_PRESSURE
};

class SensorData
{
private:
    SensorType m_sensor_type;
    float m_sensor_reading;
public:
    SensorData(SensorType type , float reading):m_sensor_type{type}, m_sensor_reading{reading} {}
    ~SensorData() {}
    SensorData(const SensorData&)=delete;
    SensorData& operator = (const SensorData&)=delete;
    SensorData(SensorData&&)=delete;
    SensorData& operator = (SensorData&&)=delete;
   

    void setSensorReading(float sensor_reading) { m_sensor_reading = sensor_reading; }

    
    
};

void ResetSensor(SensorData& s){
    s.setSensorReading(0.0f);
}

SensorData MakeNewSensor(){
    float val {0.0f};
    std::cin>>val;

    SensorData s1(SensorType::TYPE_PRESSURE,val); 
}

int main(){
    SensorData(SensorType::FUEL_GUAGE, 28.1);
}