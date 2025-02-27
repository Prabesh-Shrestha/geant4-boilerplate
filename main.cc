
#include <G4RunManager.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
#include <G4VisExecutive.hh>
#include <iostream>

int main(int argc, char **argv) {
    G4RunManager *runManager = new G4RunManager();

    // runManager->SetUserInitialization(new MyDetectorConstruction());
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialise();

    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    ui->SessionStart();
    return 0;
}
