from tkinter import *

class controller:
    
    def __init__(self,ras=300):
        self.ras = ras
        self.window = Tk()
        self.window.geometry(str(str(ras)+'x'+str(ras)))
        self.window.title("pult")
        self.canvas = Canvas(self.window,width=self.ras,height=self.ras,bg="white")
        self.canvas.place(x=0,y=0)
        #self.canvas.bind("<Button-1>", self.click1)   # ПКМ
        self.canvas.create_oval([50,self.ras-50],[50,self.ras-50],fill="red", outline="black")
        #canvas.create_oval([x*ras+ras/2+ras/10,(y-1)*ras+ras/2*3+ras/10],[x*ras+ras/2*3-ras/10,(y-1)*ras+ras/2*5-ras/10],fill="black", outline="black")
        #self.update_monitor()

    def update_monitor(self):
        #self.canvas.delete("all")
        self.canvas.create_oval([10,self.ras-10],[10,self.ras-10],fill="red", outline="black")
        self.canvas.update()
        self.window.update()

    
if __name__=="__main__":
    
    
    
    pult = controller()
    pult.window.mainloop()
    
    print("end")

#import tkinter as tk
 
window = Tk()
 
frame1 = Frame(master=window, height=100, bg="red")
frame1.pack(fill=X)
 
frame2 = Frame(master=window, height=50, bg="yellow")
frame2.pack(fill=X)
 
frame3 = Frame(master=window, height=25, bg="blue")
frame3.pack(fill=X)
 
window.mainloop()
    

