#include <iostream>
#include <vector>

std::string MOUNTPOINT = "/mnt";

void cmd(std::string s){
    std::cout << s << std::endl;
    system(s.c_str());
    
}

void cmds(std::vector<std::string> v){
    for (unsigned int i=0; i<v.size(); i++){
        cmd(v[i]);
    }
}

int main(){
    std::string num;
    std::cout << "input integer for /dev/sda: ";
    std::cin >> num;
    
    std::cout << "***sudo grub-install /dev/sda\n***sudo update-grub" << std::endl;
    
    std::vector<std::string> v{
        "sudo mount /dev/sda" + num,
        "sudo mount -t proc none "+MOUNTPOINT+"/proc",
        "sudo mount -o bind /dev "+MOUNTPOINT+"/dev",
        "sudo mount -o bind /sys "+MOUNTPOINT+"/sys",
        "sudo chroot "+MOUNTPOINT,
        //user in mountpoint, completes after user exits
        "sudo umount "+MOUNTPOINT+"/sys",
        "sudo umount "+MOUNTPOINT+"/dev",
        "sudo umount "+MOUNTPOINT+"/proc",
        "sudo umount "+MOUNTPOINT
        
    };
    cmds(v);
}
