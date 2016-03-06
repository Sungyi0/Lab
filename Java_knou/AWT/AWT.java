import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
	public MyFrame(String title) {
		super(title);
		this.setSize(400, 300);
		this.setVisible(true);
		
		WindowListener xListener = new WindowAdapter() {
			public void windowClosing(WindowEvent ev) {
				System.exit(0);
			}
		};
		
		this.addWindowListener(xListener);
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