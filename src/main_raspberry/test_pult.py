from tkinter import *
from threading import Thread
from time import sleep

class controller(Thread):
    
    def __init__(self,ras=300):
        Thread.__init__(self)
        self.ras = ras
        self.enable = True
        self.flag = False
        self.mouse_error_x = 0
        self.mouse_error_y = 0
        
        self.start()
        
    def loop(self):
        self.window = Tk()
        self.window.geometry(str(str(self.ras)+'x'+str(self.ras)))
        self.window.title("pult")
        self.canvas = Canvas(self.window,width=self.ras,height=self.ras,bg="white")
        self.canvas.place(x=0,y=0)
        self.canvas.create_oval([50,50],[self.ras-50,self.ras-50],fill="white", outline="black")
        self.canvas.create_text(self.ras/2,self.ras/2,text="нажми сюда",font=11,justify=CENTER,fill="black")
        #self.update_monitor()
        self.canvas.bind("<Button-1>", self.click)   # ПКМ
        self.window.mainloop()
        self.enable = False
        
    def mouse_coo(self):
        try:
            if (self.flag):
                return self.window.winfo_pointerx()-self.mouse_error_x,self.window.winfo_pointery()-self.mouse_error_y
        except TclError:
            return 0,0

    def update_monitor(self):
        if self.flag: return
        self.flag = True

        try:
            print(((self.ras-100)/2))
            while self.enable and self.enable:
                self.canvas.delete("all")
                self.canvas.create_oval([50,50],[self.ras-50,self.ras-50],fill="white", outline="black")
                self.canvas.create_oval([100,100],[self.ras-100,self.ras-100],fill="white", outline="black")

                x, y = self.mouse_coo()
                if ((self.ras/2-x)**2+(self.ras/2-y)**2)**(1/2)>((self.ras-100)/2):
                    x = self.ras/2
                    y = self.ras/2
                # if ((self.ras/2-x)**2+(self.ras/2-y)**2)**(1/2)>((self.ras-200)/2):
                #     x = self.old_x
                #     y = self.old_y

                self.canvas.create_oval([x-5,y-5],[x+5,y+5],fill="red", outline="black")


                self.canvas.update()
                self.window.update()

                sleep(0.1)
        except TclError: pass # _tkinter.

    def click(self,event):
        self.mouse_error_x = self.window.winfo_pointerx() - event.x
        self.mouse_error_y = self.window.winfo_pointery() - event.y
        self.update_monitor()
        # while self.enable:
        #     try: self.update_monitor(event)
        #     except RuntimeError: print("ERROR")
            

    def run(self): # Запуск потока
        #sleep(1)
        # выполняется один раз
        # while self.enable:
        #     try: self.update_monitor()
        #     except RuntimeError: print("ERROR")
        #     sleep(0.1)
        #self.window.mainloop()
        self.loop()
        

    
if __name__=="__main__":
    
    
    
    pult = controller()
    #pult.start()
    #pult.window.mainloop()
    #pult.window.mainloop()
    
    print("end")
    sleep(3)
    #pult.enable = False