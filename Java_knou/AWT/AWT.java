import java.awt.*;

class MyFrame extends Frame {
	private FileDialog fDialog = null;
	public MyFrame(String title) {
	super(title);
	this.setSize(400, 300);
	this.setVisible(true);
	}
	
	public void paint(Graphics g) {
		super.paint(g);
		if (fDialog != null) putMsg(g);
	}
	public void update(Graphics g) {
		putMsg(g);
	}
	public void setDialog(FileDialog f) {
		fDialog = f;
	}
	private void putMsg(Graphics g) {
		g.drawString("Directory: " + fDialog.getDirectory(), 10, 50);
		g.drawString("File: " + fDialog.getFile(), 10, 100);
	}
}

public class AWT {
	public static void main(String args[]) {
		MyFrame myFrame = new MyFrame("FileDialogTest");
		FileDialog f = new FileDialog(myFrame, "Open", FileDialog.LOAD);
		
		f.setVisible(true);
		myFrame.setDialog(f);
		
		myFrame.repaint();
	}
}