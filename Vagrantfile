Vagrant.configure(2) do |config|

  # config.vm.box = 'generic/arch'
  config.vm.box = "jeffnoxon/ubuntu-20.04-arm64"

  # synced folder
  config.vm.synced_folder '.', '/xv6'

  # disable default synced folder
  config.vm.synced_folder '.', '/vagrant', disabled: true

  # install packages
  config.vm.provision 'shell', inline: <<-EOS
    export TZ=Asia/Taipei LANG=en_US.utf8 LANGUAGE=en_US.UTF-8 LC_ALL=en_US.UTF-8 DEBIAN_FRONTEND=noninteractive

    sudo apt-get update && \
      apt-get install -y git curl vim build-essential \
      gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu \
      binutils-riscv64-linux-gnu libpixman-1-dev gcc-riscv64-unknown-elf \
      libglib2.0-dev pkg-config

    curl -LJO https://download.qemu.org/qemu-5.1.0.tar.xz

    tar xf qemu-5.1.0.tar.xz # buildkit

    cd qemu-5.1.0 && ./configure --disable-kvm --disable-werror --prefix=/usr/local --target-list=riscv64-softmmu && make && make install

    echo "add-auto-load-safe-path /xv6/.gdbinit" >> /root/.gdbinit
  EOS
end
