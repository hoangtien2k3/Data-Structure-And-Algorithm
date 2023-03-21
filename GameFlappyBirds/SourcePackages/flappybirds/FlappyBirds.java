package GameFlappyBirds.SourcePackages.flappybirds;

import GameFlappyBirds.SourcePackages.gamesframework.AFrameOnImage;
import GameFlappyBirds.SourcePackages.gamesframework.Animation;
import GameFlappyBirds.SourcePackages.gamesframework.GameScreen;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class FlappyBirds extends GameScreen {

    private BufferedImage birds;
    private Animation bird_anim;

    public static float g = 0.1f; // trọng lượng( gia tốc hướng tâm )

    private Bird bird;


    public FlappyBirds() throws IOException {
        super(800, 600);

        try {
            // add bức ảnh con chim Flappy Bird vào.
            birds = ImageIO.read(new File("Image/bird_sprite.png"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        // số lần flappy bird xuất hiện. (có nghĩ là 3 con chim nó se đè lên nhau để tạo ra hình ảnh di chuyển).
        // 70 có nghĩ là set thời gian vỗ cánh của con chim (milisecond)
        bird_anim = new Animation(70);


        // sét tạo độ, và độ dài, rộng cho con chim.
        AFrameOnImage f;
        f = new AFrameOnImage(0, 0, 60, 60);
        bird_anim.AddFrame(f);
        f = new AFrameOnImage(60, 0, 60, 60);
        bird_anim.AddFrame(f);
        f = new AFrameOnImage(120, 0, 60, 60);
        bird_anim.AddFrame(f);
        f = new AFrameOnImage(60, 0, 60, 60);
        bird_anim.AddFrame(f);


        bird = new Bird(350, 250, 50, 50);


        BeginGame();
    }


    public static void main(String[] args) throws IOException {
        new FlappyBirds();
    }


    @Override
    public void GAME_UPDATE(long deltaTime) {
        bird_anim.Update_Me(deltaTime);
        bird.update(deltaTime);
    }

    @Override
    public void GAME_PAINT(Graphics2D g2) {
        if (birds != null) {
            bird_anim.PaintAnims((int) bird.getPosX(), (int) bird.getPosY(), birds, g2, 0, 0);
        }
    }

    @Override
    public void KEY_ACTION(KeyEvent e, int Event) {
        // có nghĩa chỗ này nó sẽ bắt sự kiện nhấn, (con chim đang rơi, nếu nhấn thì con chim nó sẽ bay lên)
        if (Event == KEY_PRESSED) {
            bird.fly();
        }
    }

}
