import java.awt.*;
import java.awt.event.*;

class MyListener implements WindowListener {
	public void windowClosing(WindowEvent ev) {
		System.exit(0);
	}
	
	public void windowActivated(WindowEvent ev) {}
	public void windowClosed(WindowEvent ev) {}
	public void windowDeactivated(WindowEvent ev) {}
	public void windowDeiconified(WindowEvent ev) {}
	public void windowIconified(WindowEvent ev) {}
	public void windowOpened(WindowEvent ev) {}
}

class MyFrame extends Frame {
	public MyFrame(String title) {
		super(title);
		this.setSize(400, 300);
		this.setVisible(true);
		
		this.addWindowListener(new MyListener());
	}
	
	public void paint(Graphics g) {
		g.drawString("Hello AWT", 150, 150);
	}
}

public class AWT {
	public static void main(String args[]) {
		MyFrame myFrame = new MyFrame("Hello AWT");
	}
}