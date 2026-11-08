#include <iostream>
#include <string>
using namespace std;

class CloudResource {
protected:
    string resourceID;
    double baseHourlyRate;
    string* resourceMeta;

public:
    CloudResource(string id, double rate) {
        resourceID = id;
        baseHourlyRate = rate;
        resourceMeta = new string("Resource Metadata: ID = " + id);
        cout << "CloudResource constructor called" << endl;
    }

    virtual double calculateCost(double hours) {
        return baseHourlyRate * hours;
    }

    virtual void showMetadata() {
        cout << *resourceMeta << endl;
    }

    virtual ~CloudResource() {
        delete resourceMeta;
        cout << "CloudResource destructor called (resourceMeta freed)" << endl;
    }
};

class ServerInstance : public CloudResource {
protected:
    int cpuCores;
    double ramGB;
    string* serverMeta;

public:
    ServerInstance(string id, double rate, int cores, double ram) : CloudResource(id, rate) {
        cpuCores = cores;
        ramGB = ram;
        serverMeta = new string("Server Metadata: " + to_string(cores) + " cores, " + to_string((int)ram) + " GB RAM");
        cout << "ServerInstance constructor called" << endl;
    }

    double calculateCost(double hours) {
        return (baseHourlyRate + (cpuCores * 0.05) + (ramGB * 0.02)) * hours;
    }

    void showMetadata() {
        CloudResource::showMetadata();
        cout << *serverMeta << endl;
    }

    ~ServerInstance() {
        delete serverMeta;
        cout << "ServerInstance destructor called (serverMeta freed)" << endl;
    }
};

class GPUAcceleratedServer : public ServerInstance {
private:
    int gpuCount;
    double gpuModelTierMultiplier;
    string* gpuMeta;

public:
    GPUAcceleratedServer(string id, double rate, int cores, double ram, int gpus, double tier)
        : ServerInstance(id, rate, cores, ram) {
        gpuCount = gpus;
        gpuModelTierMultiplier = tier;
        gpuMeta = new string("GPU Metadata: " + to_string(gpus) + " GPUs, tier multiplier " + to_string(tier));
        cout << "GPUAcceleratedServer constructor called" << endl;
    }

    double calculateCost(double hours) {
        double serverCost = ServerInstance::calculateCost(hours);
        double gpuFee = gpuCount * 1.5 * gpuModelTierMultiplier * hours;
        cout << "Server cost (from ServerInstance): $" << serverCost << endl;
        cout << "GPU processing fee: $" << gpuFee << endl;
        return serverCost + gpuFee;
    }

    void showMetadata() {
        ServerInstance::showMetadata();
        cout << *gpuMeta << endl;
    }

    ~GPUAcceleratedServer() {
        delete gpuMeta;
        cout << "GPUAcceleratedServer destructor called (gpuMeta freed)" << endl;
    }
};

int main() {
    cout << "===== Creating GPU server =====" << endl;
    {
        GPUAcceleratedServer gpuServer("GPU-NODE-01", 0.50, 8, 32.0, 2, 1.5);

        cout << "\n===== Metadata =====" << endl;
        gpuServer.showMetadata();

        cout << "\n===== 24 hour usage cost =====" << endl;
        double total = gpuServer.calculateCost(24);
        cout << "Total cost for 24 hours: $" << total << endl;

        cout << "\n===== Object going out of scope =====" << endl;
    }
    cout << "\n===== Back in main, all destructors done =====" << endl;

    return 0;
}