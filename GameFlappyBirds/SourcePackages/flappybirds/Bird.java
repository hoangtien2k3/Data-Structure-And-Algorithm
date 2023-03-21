package GameFlappyBirds.SourcePackages.flappybirds;

import GameFlappyBirds.SourcePackages.gamesframework.Objects;

public class Bird extends Objects {
    private float vt = 0; // tốc độ rơi của con chim hiện tại set cho nó bằng 0;
    public Bird(int x, int y, int w, int h) {
        super(x, y, w, h);
    }

    public void update(long deltaTime) {
        // Có nghĩa là vận tốc ban đầu của con chim bằng gia tốc
        vt += FlappyBirds.g;

        // thay đổi tọa độ Y bằng tọa độ Y + vận tốc. ( Thì bây giờ tốc độ rơi của con chim nó sẽ tăng lên)
        this.setPosY(this.getPosY() + vt);
    }

    public void fly() {
        vt = -3;
    }

}
