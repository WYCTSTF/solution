package JAVA.Interface;

interface Alarmable {
	public void alarming();
	public Boolean isOpenOrClose();
}
class Alarmber implements Alarmable {
	private Boolean alarmStatus;
	public void alarming() {
		if (alarmStatus)
			System.out.println("Alarming!");
		else
			System.out.println("No need to alram");
	}
	public Boolean isOpenOrClose() { return alarmStatus; }
	public void TurnOn() { alarmStatus = true; }
	public void ShutDown() { alarmStatus = false; }
}
class Door extends Alarmber {
	private Boolean doorStatus;
	public void openDoor() { doorStatus = true; }
	public void closeDoor() { doorStatus = false; }
	@Override
	public Boolean isOpenOrClose() { return doorStatus; }
}
class AlarmDoor extends Door {}
public class Tester {
	public static void main(String[] args) {
		AlarmDoor a1 = new AlarmDoor();
		a1.TurnOn(); a1.closeDoor();
		a1.alarming();
		if(a1.isOpenOrClose()) System.out.println("Door is open");
		else System.out.println("Door is close");
	}
}