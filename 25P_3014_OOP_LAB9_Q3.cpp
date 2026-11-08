#include <iostream>
using namespace std;

class RadarSystem {
protected:
    double targetDistance;
    double targetAzimuth;

public:
    RadarSystem(double d, double a) {
        targetDistance = d;
        targetAzimuth = a;
    }

    void renderDisplay() {
        cout << "[Radar] Sweep -> Distance: " << targetDistance
             << " km, Azimuth: " << targetAzimuth << " degrees" << endl;
             cout<<endl;
    }
};

class NavigationSystem {
protected:
    double gpsLatitude;
    double gpsLongitude;

public:
    NavigationSystem(double lat, double lon) {
        gpsLatitude = lat;
        gpsLongitude = lon;
    }

    void renderDisplay() {
        cout << "[Navigation] Terrain Map Grid -> Latitude: " << gpsLatitude
             << ", Longitude: " << gpsLongitude << endl;
    }
};

class HeadsUpDisplay : public RadarSystem, public NavigationSystem {
private:
    bool nightVisionActive;

public:
    HeadsUpDisplay(double d, double a, double lat, double lon, bool nv)
        : RadarSystem(d, a), NavigationSystem(lat, lon) {
        nightVisionActive = nv;
    }

    void renderDisplay() {
        cout << "[HUD] Rendering full display" << endl;
        RadarSystem::renderDisplay();
        NavigationSystem::renderDisplay();
        if (nightVisionActive) {
            cout << "[HUD] Night Vision: ON" << endl;
        }
        else {
            cout << "[HUD] Night Vision: OFF" << endl;
        }
    }

    void renderTacticalOverlay(bool radarMode, bool navMode) {
        cout << "[HUD] Tactical Overlay" << endl;
        if (radarMode && navMode) {
            cout << "Mode: Radar + Navigation" << endl;
            RadarSystem::renderDisplay();
            NavigationSystem::renderDisplay();
        }
        else if (radarMode) {
            cout << "Mode: Radar only" << endl;
            RadarSystem::renderDisplay();
        }
        else if (navMode) {
            cout << "Mode: Navigation only" << endl;
            NavigationSystem::renderDisplay();
        }
        else {
            cout << "Mode: All systems OFF" << endl;
        }
    }
};

int main() {
    HeadsUpDisplay hud(45.5, 120.0, 33.6844, 73.0479, true);

    cout << "===== Collision explanation =====" << endl;
    cout << "RadarSystem and NavigationSystem both have renderDisplay()." << endl;
    cout << "Without an override in HUD, hud.renderDisplay() would be ambiguous (compiler error)." << endl;
    cout << "HUD overrides it and calls both bases using the scope resolution operator." << endl;

    cout << "\n===== 1) HUD's own renderDisplay() =====" << endl;
    hud.renderDisplay();

    cout << "\n===== 2) Calling each base version explicitly =====" << endl;
    hud.RadarSystem::renderDisplay();
    hud.NavigationSystem::renderDisplay();

    cout << "\n===== 3) Tactical overlay modes =====" << endl;
    hud.renderTacticalOverlay(true, false);
    cout << endl;
    hud.renderTacticalOverlay(false, true);
    cout << endl;
    hud.renderTacticalOverlay(true, true);
    cout << endl;
    hud.renderTacticalOverlay(false, false);
    cout<<endl;
    return 0;
}